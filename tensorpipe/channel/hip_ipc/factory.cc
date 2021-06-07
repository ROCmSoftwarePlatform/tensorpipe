// !!! This is a file automatically generated by hipify!!!
/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <tensorpipe/channel/hip_ipc/factory.h>

#include <tensorpipe/channel/context_boilerplate.h>
#include <tensorpipe/channel/hip_ipc/channel_impl.h>
#include <tensorpipe/channel/hip_ipc/context_impl.h>

namespace tensorpipe {
namespace channel {
namespace cuda_ipc {

std::shared_ptr<Context> create() {
  return std::make_shared<ContextBoilerplate<ContextImpl, ChannelImpl>>();
}

} // namespace cuda_ipc
} // namespace channel
} // namespace tensorpipe
