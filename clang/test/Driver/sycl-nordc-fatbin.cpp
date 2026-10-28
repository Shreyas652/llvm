// REQUIRES: spirv-registered-target, x86-registered-target

<<<<<<< HEAD
// REQUIRES: spirv-to-ir-wrapper, sycl-post-link

/// Verify that no-RDC emits image address/size records in .tgtimg, while RDC
/// embeds device code for linking in .llvm.offloading.
// RUN: %clangxx --target=x86_64-unknown-linux-gnu -fsycl --offload-new-driver --no-offloadlib -fno-gpu-rdc \
=======
/// Verify which section carries the SYCL device binary in the host object.
// RUN: %clangxx --target=x86_64-unknown-linux-gnu -fsycl \
// RUN:   --no-offloadlib -fno-gpu-rdc \
>>>>>>> e4225302cd112b4f72bb33374f5f800cb7be8d09
// RUN:   -c %s -o %t.nordc.o
// RUN: llvm-readelf -S %t.nordc.o \
// RUN:   | FileCheck -check-prefix=NORDC %s --implicit-check-not='.llvm.offloading'

<<<<<<< HEAD
/// -fsycl-link also forwards --sycl-device-link to the per-TU no-RDC job.
/// Fatbin-only completion must skip the device-link copy branch.
// RUN: %clangxx --target=x86_64-unknown-linux-gnu -fsycl --offload-new-driver --no-offloadlib -fno-gpu-rdc \
// RUN:   -fsycl-link -c %s -o %t.nordc.devlink.o
// RUN: llvm-readelf -S %t.nordc.devlink.o \
// RUN:   | FileCheck -check-prefix=NORDC %s --implicit-check-not='.llvm.offloading'

// RUN: %clangxx --target=x86_64-unknown-linux-gnu -fsycl --offload-new-driver --no-offloadlib -fgpu-rdc \
=======
// RUN: %clangxx --target=x86_64-unknown-linux-gnu -fsycl \
// RUN:   --no-offloadlib -fgpu-rdc \
>>>>>>> e4225302cd112b4f72bb33374f5f800cb7be8d09
// RUN:   -c %s -o %t.rdc.o
// RUN: llvm-readelf -S %t.rdc.o \
// RUN:   | FileCheck -check-prefix=RDC %s --implicit-check-not='.tgtimg'

/// The choice does not depend on the object format.
<<<<<<< HEAD
// RUN: %clangxx --target=x86_64-pc-windows-msvc -fsycl --offload-new-driver --no-offloadlib -fno-gpu-rdc \
=======
// RUN: %clangxx --target=x86_64-pc-windows-msvc -fsycl \
// RUN:   --no-offloadlib -fno-gpu-rdc \
>>>>>>> e4225302cd112b4f72bb33374f5f800cb7be8d09
// RUN:   -c %s -o %t.nordc.obj
// RUN: llvm-readobj --sections %t.nordc.obj \
// RUN:   | FileCheck -check-prefix=NORDC %s --implicit-check-not='.llvm.offloading'

<<<<<<< HEAD
// RUN: %clangxx --target=x86_64-pc-windows-msvc -fsycl --offload-new-driver --no-offloadlib -fgpu-rdc \
=======
// RUN: %clangxx --target=x86_64-pc-windows-msvc -fsycl \
// RUN:   --no-offloadlib -fgpu-rdc \
>>>>>>> e4225302cd112b4f72bb33374f5f800cb7be8d09
// RUN:   -c %s -o %t.rdc.obj
// RUN: llvm-readobj --sections %t.rdc.obj \
// RUN:   | FileCheck -check-prefix=RDC %s --implicit-check-not='.tgtimg'

// NORDC: .tgtimg
// RDC: .llvm.offloading

void f() {}
