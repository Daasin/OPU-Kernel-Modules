/*
 * SPDX-FileCopyrightText: Copyright (c) 2022 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

/*!
 * @file  nv_sriov_defines.h
 * @brief Defines for doorbell tokens and scratch registers index.
 * 
 * Define:- 
 *    - VF scratch registers index used in VGPU-GSP RPC setup
 *    - VF scratch registers index used in FECS tracing support
 *    - Doorbell interrupt handles for Guest RM to GSP-Plugin communication
 *    - Doorbell interrupt handles for Host CPU-Plugin to GSP-Plugin communication
 */

//
// Ring Doorbell register to setup GSP Notification interrupt
// We have total 4096 bits for notifications (128 notify leaf registers).
// Setup to use leaf register index 0 for all communications from Guest VM to GSP-Plugin
// bit index 0x0 to 0xF used for CPU-Plugin <----> GSP-Plugin communication
// bit index 0x10 to 0x1F used for Guest VM <----> GSP-Plugin communication
// bit index 0x10 in the gsp notify register is used for RPC setup request
// bit index 0x11 in the gsp notify register is used for sending RPC send request
//

// These defines are applicable per VM i.e. replicated per VM.
#define NV_DOORBELL_NOTIFY_LEAF_VF_CPU_PLUGIN_REQUEST                           1:1
#define NV_DOORBELL_NOTIFY_LEAF_VF_CPU_PLUGIN_REQUEST_EN                        (0x1)
#define NV_DOORBELL_NOTIFY_LEAF_VF_CPU_PLUGIN_REQUEST_DIS                       (0x0)
#define NV_DOORBELL_NOTIFY_LEAF_SERVICE_NON_REPLAYABLE_FAULT_REQUEST            2:2
#define NV_DOORBELL_NOTIFY_LEAF_SERVICE_NON_REPLAYABLE_FAULT_REQUEST_EN         (0x1)
#define NV_DOORBELL_NOTIFY_LEAF_SERVICE_NON_REPLAYABLE_FAULT_REQUEST_DIS        (0x0)
#define NV_DOORBELL_NOTIFY_LEAF_VF_RPC_SETUP_REQUEST                            16:16
#define NV_DOORBELL_NOTIFY_LEAF_VF_RPC_SETUP_REQUEST_EN                         (0x1)
#define NV_DOORBELL_NOTIFY_LEAF_VF_RPC_SETUP_REQUEST_DIS                        (0x0)
#define NV_DOORBELL_NOTIFY_LEAF_VF_RPC_MESSAGE_REQUEST                          17:17
#define NV_DOORBELL_NOTIFY_LEAF_VF_RPC_MESSAGE_REQUEST_EN                       (0x1)
#define NV_DOORBELL_NOTIFY_LEAF_VF_RPC_MESSAGE_REQUEST_DIS                      (0x0)

#define NV_DOORBELL_NOTIFY_LEAF_VF_CPU_PLUGIN_HANDLE                            (0 ? NV_DOORBELL_NOTIFY_LEAF_VF_CPU_PLUGIN_REQUEST)
#define NV_DOORBELL_NOTIFY_LEAF_SERVICE_NON_REPLAYABLE_FAULT_HANDLE             (0 ? NV_DOORBELL_NOTIFY_LEAF_SERVICE_NON_REPLAYABLE_FAULT_REQUEST)
#define NV_DOORBELL_NOTIFY_LEAF_VF_RPC_SETUP_HANDLE                             (0 ? NV_DOORBELL_NOTIFY_LEAF_VF_RPC_SETUP_REQUEST)
#define NV_DOORBELL_NOTIFY_LEAF_VF_RPC_MESSAGE_HANDLE                           (0 ? NV_DOORBELL_NOTIFY_LEAF_VF_RPC_MESSAGE_REQUEST)

// current write offset of the FECS trace buffer
#define NV_VF_SCRATCH_REGISTER_FECS_TRACE_WR_RD_OFFSET                          0x0
// current read offset of the FECS trace buffer
#define NV_VF_SCRATCH_REGISTER_FECS_TRACE_RD_RD_OFFSET                          0x1

// used in VGPU-GSP RPC setup
#define NV_VF_SCRATCH_REGISTER_GUEST_RPC_LO                                     0x2
// used in VGPU-GSP RPC setup
#define NV_VF_SCRATCH_REGISTER_GUEST_RPC_HI                                     0x3
