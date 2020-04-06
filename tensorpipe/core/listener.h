/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <functional>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include <tensorpipe/common/error.h>
#include <tensorpipe/core/context.h>

namespace tensorpipe {

class Pipe;

// The listener.
//
// Listeners are used to produce pipes. Depending on the type of the
// context, listeners may use a variety of addresses to listen on. For
// example, for TCP/IP sockets they listen on an IPv4 or IPv6 address,
// for Unix domain sockets they listen on a path, etcetera.
//
// A pipe can only be accepted from this listener after it has been
// fully established. This means that both its connection and all its
// side channels have been established.
//
class Listener final : public std::enable_shared_from_this<Listener> {
  // Use the passkey idiom to allow make_shared to call what should be a private
  // constructor. See https://abseil.io/tips/134 for more information.
  struct ConstructorToken {};

 public:
  Listener(
      ConstructorToken,
      std::shared_ptr<Context::PrivateIface>,
      const std::vector<std::string>&);

  //
  // Entry points for user code
  //

  using accept_callback_fn =
      std::function<void(const Error&, std::shared_ptr<Pipe>)>;

  void accept(accept_callback_fn);

  // Returns map with the materialized address of listeners by transport.
  //
  // If you don't bind a transport listener to a specific port or address, it
  // may generate its address automatically. Then, in order to connect to the
  // listener, the user must use a separate mechanism to communicate the
  // materialized address to whoever wants to connect.
  //
  const std::map<std::string, std::string>& addresses() const;

  // Returns materialized address for specific transport.
  //
  // See `addresses()` for more information.
  //
  const std::string& address(const std::string& transport) const;

  // Returns URL with materialized address for specific transport.
  //
  // See `addresses()` for more information.
  //
  std::string url(const std::string& transport) const;

  // Put the listener in a terminal state, aborting its pending operations and
  // rejecting future ones, and release its resrouces. This may be carried out
  // asynchronously, in background. Since the pipes may occasionally use the
  // listener to open new connections, closing a listener may trigger errors
  // in the pipes.
  void close();

  ~Listener();

 private:
  class PrivateIface {
   public:
    using connection_request_callback_fn = std::function<void(
        const Error&,
        std::string,
        std::shared_ptr<transport::Connection>)>;

    virtual uint64_t registerConnectionRequest(
        connection_request_callback_fn) = 0;

    virtual void unregisterConnectionRequest(uint64_t) = 0;

    virtual const std::map<std::string, std::string>& addresses() const = 0;

    virtual ~PrivateIface() = default;
  };

  class Impl;

  // Using a shared_ptr allows us to detach the lifetime of the implementation
  // from the public object's one and perform the destruction asynchronously.
  std::shared_ptr<Impl> impl_;

  friend class Context;
  friend class Pipe;
};

} // namespace tensorpipe
