# Package summary
SUMMARY = "My App"
# License, for example MIT
LICENSE = "MIT"
# License checksum file is always required
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

# ioctl.c from local file
SRC_URI = "file://ioctl.c"

# Set LDFLAGS options provided by the build system
TARGET_CC_ARCH += "${LDFLAGS}"

# Change source directory to workdirectory where ioctl.c is
S = "${WORKDIR}"

# Compile ioctl from sources, no Makefile
do_compile() {
    ${CXX} -Wall ioctl.c -o ioctl
}

# Install binary to final directory /usr/bin
do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${S}/ioctl ${D}${bindir}
}
