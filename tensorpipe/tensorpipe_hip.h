// !!! This is a file automatically generated by hipify!!!
/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <tensorpipe/config.h>

// High-level API

#include <tensorpipe/core/context.h>
#include <tensorpipe/core/error.h>
#include <tensorpipe/core/listener.h>
#include <tensorpipe/core/message.h>
#include <tensorpipe/core/pipe.h>

#include <tensorpipe/common/buffer.h>

#include <tensorpipe/common/cpu_buffer.h>
#if TENSORPIPE_SUPPORTS_CUDA
#include <tensorpipe/common/hip_buffer.h>
#endif // TENSORPIPE_SUPPORTS_CUDA

// Transports

#include <tensorpipe/transport/context.h>
#include <tensorpipe/transport/error.h>

#include <tensorpipe/transport/uv/error.h>
#include <tensorpipe/transport/uv/factory.h>
#include <tensorpipe/transport/uv/utility.h>

#if TENSORPIPE_HAS_SHM_TRANSPORT
#include <tensorpipe/transport/shm/factory.h>
#endif // TENSORPIPE_HAS_SHM_TRANSPORT

#if TENSORPIPE_HAS_IBV_TRANSPORT
#include <tensorpipe/transport/ibv/error.h>
#include <tensorpipe/transport/ibv/factory.h>
#include <tensorpipe/transport/ibv/utility.h>
#endif // TENSORPIPE_HAS_IBV_TRANSPORT

// Channels

#include <tensorpipe/channel/context.h>
#include <tensorpipe/channel/error.h>

#include <tensorpipe/channel/basic/factory.h>
#include <tensorpipe/channel/mpt/factory.h>
#include <tensorpipe/channel/xth/factory.h>

#if TENSORPIPE_HAS_CMA_CHANNEL
#include <tensorpipe/channel/cma/factory.h>
#endif // TENSORPIPE_HAS_CMA_CHANNEL

#if TENSORPIPE_SUPPORTS_CUDA
#include <tensorpipe/channel/hip_basic/factory.h>
#include <tensorpipe/channel/hip_xth/factory.h>

#if TENSORPIPE_HAS_CUDA_GDR_CHANNEL
#include <tensorpipe/channel/hip_gdr/factory.h>
#endif // TENSORPIPE_HAS_CUDA_GDR_CHANNEL

#if TENSORPIPE_HAS_CUDA_IPC_CHANNEL
#include <tensorpipe/channel/hip_ipc/factory.h>
#endif // TENSORPIPE_HAS_CUDA_IPC_CHANNEL
#endif // TENSORPIPE_SUPPORTS_CUDA
