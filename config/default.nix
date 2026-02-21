{ pkgs ? import ../src/nix/pinned-nixpkgs.nix {}
  , firmware ? import ../src {}
}:

let
  config = ./.;


  gatedKeys =  /zmk-modules/zmk-gated-key;
  vim =  /zmk-modules/zmk-vim;

  tristate = pkgs.fetchFromGitHub {
    owner = "dhruvinsh";
    repo = "zmk-tri-state";
    rev = "ebbc1f0ccdb51669650bb0ac3e34920d09e62400";
    sha256 = "sha256-f+8zBdqKGlFFdXZ/UkSgc+HZWDfGzKyw/VjMqdwHYok=";
  };

  autoLayer = pkgs.fetchFromGitHub {
    owner = "urob";
    repo = "zmk-auto-layer";
    rev = "main";
    sha256 = "sha256-a7SKPhEJpSha0IETeue3YM2vVF07sqEHFtDWdvyCt/s=";
  };

  myModules = [
                 gatedKeys
                 tristate
                 autoLayer
              ];

  glove80_left  = firmware.zmk.override {
    board = "glove80_lh";
    keymap = "${config}/glove80.keymap";
    kconfig = "${config}/glove80.conf";
    extraModules = myModules;
  };

  glove80_right  = firmware.zmk.override {
    board = "glove80_rh";
    keymap = "${config}/glove80.keymap";
    kconfig = "${config}/glove80.conf";
    extraModules = myModules;
  };

in firmware.combine_uf2 glove80_left glove80_right
