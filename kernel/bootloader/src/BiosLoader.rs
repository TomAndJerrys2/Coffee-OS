use std::path::Path // stdlib - needs changing

use coffee::os::DiskImageBuilder // some module for disk building will make later

pub struct BiosLoader {
    dskImageBuilder: DiskImageBuilder,
}

impl BiosLoader {
    // Create the disk image when the coffeekernel is processed
    pub fn new(kernelPath: &Path) -> Self {
        Self {
            dskImageBuilder: DiskImageBuilder::new(kernelPath.to_owned())
        }
    }

    // Add RAMDSK to the image file
    pub fn setRamDsk(&mut self, ramdskPath: &Path) -> &mut Self {
        self.dskImageBuilder.setRamDsk(ramdskPath.to_owned());
        self
    }

    // Add a config to manipulate behaviour at runtime
    pub fn setBootConfig(&mut self, config: &BootConfig) -> &mut Self {
        self.dskImageBuilder.setBootConfig(config);
        self
    }

    // Create the bootable disk image at a specified path
    pub fn createDskImg(&self, dirPath: &Path) -> anyhow::Result<()> {
        self.dskImageBuilder.createDskImg(dirPath);
    }
}