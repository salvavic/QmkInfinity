# Layout de Salvador
make ergodox_infinity:salvavic:dfu-util
git add submodule https://github.com/salvavic/QmkInfinity.git keyboards/ergodox_inifinit/keymaps/salvavic
git submodules init
git submodules update
qmk setup

