static message: &[u8] = b"Hello";

#[unsafe(no_mangle)]
pub extern "C" fn start() -> ! {
    let visualBuffer = 0xb8000 as *mut u8; // buffer as a raw pointer

    for (bit, &byte) in message.iter().enumerate() {
        unsafe {
            *visualBuffer.offset(bit as isize * 2);
            *visualBuffer.offset(bit as isize * 2 + 1) = 0xb;
        }
    }

    loop {}
}
