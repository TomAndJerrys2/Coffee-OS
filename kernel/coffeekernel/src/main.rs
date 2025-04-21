// Entry Point for the CoffeeKernel
// C/C++ Binaries will be built using CoffeeHandler

#![no_std]
#![no_main]

use core::panic::PanicInfo;

// On kernel panic
#![panic_handler]
fn panic(info: &PanicInfo) -> ! {
    loop {}
}

#[unsafe(no_mangle)]
pub extern "C" fn start() -> ! {
    // Program entry point for the FSB
    loop {}
}