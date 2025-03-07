//===- OnDiskCommon.h -------------------------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_CAS_ONDISKCOMMON_H
#define LLVM_LIB_CAS_ONDISKCOMMON_H

#include "llvm/Support/Error.h"
#include <optional>

namespace llvm::cas::ondisk {

/// Retrieves an overridden maximum mapping size for CAS files, if any,
/// speicified by LLVM_CAS_MAX_MAPPING_SIZE in the environment or set by
/// `setMaxMappingSize()`. If the value from environment is unreadable, returns
/// an error.
Expected<std::optional<uint64_t>> getOverriddenMaxMappingSize();

/// Set MaxMappingSize for ondisk CAS. This function is not thread-safe and
/// should be set before creaing any ondisk CAS and does not affect CAS already
/// created. Set value 0 to use default size.
void setMaxMappingSize(uint64_t Size);

} // namespace llvm::cas::ondisk

#endif // LLVM_LIB_CAS_ONDISKCOMMON_H
