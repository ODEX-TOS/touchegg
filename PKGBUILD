#
# Touchégg : Multitouch gesture recogniser
#
# Original Maintainer: Guillaume Turchini <guillaume.turchini@gmail.com>"

_pkgname=touchegg
pkgname=tde-touchegg
pkgver=r323.c1773dc
pkgrel=1
pkgdesc='Linux multi-touch gesture recognizer'
arch=('x86_64')
url='https://github.com/ODEX-TOS/touchegg'
license=('GPL3')
source=("${_pkgname}::git+https://github.com/ODEX_TOS/touchegg.git")
depends=('libinput' 'cairo' 'systemd-libs' 'libx11' 'libxrandr' 'libxtst' 'pugixml')
makedepends=('git' 'cmake')
sha256sums=('SKIP')
conflicts=("${_pkgname}")
provides=("${_pkgname}")

pkgver() {
    cd "${_pkgname}"
    printf "r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
}

build() {
    cmake -B build -S "${_pkgname}" -DCMAKE_BUILD_TYPE=Release ..
    make -C build -j$(nproc)
}

package() {
    DESTDIR="$pkgdir" make -C build install

    # /lib is a symlink to /usr/lib on most Arch systems, this
    # workaround is needed to prevent alpm from failing with
    # a conflict
    [ -d "$pkgdir/lib" ] && mv "$pkgdir/lib" "$pkgdir/usr/lib"
}
