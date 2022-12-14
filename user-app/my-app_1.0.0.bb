# Package summary
SUMMARY = "My App"
# License, for example MIT
LICENSE = "MIT"
# License checksum file is always required
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

# my-app.c from local file
SRC_URI = "file://my-app.c"

# Set LDFLAGS options provided by the build system
TARGET_CC_ARCH += "${LDFLAGS}"

# Change source directory to workdirectory where my-app.c is
S = "${WORKDIR}"

# Compile my-app from sources, no Makefile
do_compile() {
    ${CXX} -Wall my-app.c -o my-app
}

# Install binary to final directory /usr/bin
do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${S}/my-app ${D}${bindir}
}
