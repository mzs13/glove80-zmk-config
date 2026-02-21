{ pkgs ? import ../src/nix/pinned-nixpkgs.nix {}
  , firmware ? import ../src {}
}:

let
  config = ./.;


  gatedKeys =  /zmk-modules/zmk-gated-key;
  vim =  /zmk-modules/zmk-vim;

  adaptKey = pkgs.fetchFromGitHub {
    owner = "urob";
    repo = "zmk-adaptive-key";
    rev = "v0.3.0";
    sha256 = "sha256-9c/YQlgc9guG8XmkT0pgr+ZkDVVxyhDabyd2UaZu0RQ=";
  };

  leaderKey = pkgs.fetchFromGitHub {
    owner = "urob";
    repo = "zmk-leader-key";
    rev = "legacy";
    sha256 = "sha256-6jmzby7fyNmZJTNCAT9j5+l/bbMpWEC6j5wbhVH6yFc=";
  };

  autoLayer = pkgs.fetchFromGitHub {
    owner = "urob";
    repo = "zmk-auto-layer";
    rev = "main";
    sha256 = "sha256-a7SKPhEJpSha0IETeue3YM2vVF07sqEHFtDWdvyCt/s=";
  };

  tristate = pkgs.fetchFromGitHub {
    owner = "dhruvinsh";
    repo = "zmk-tri-state";
    rev = "ebbc1f0ccdb51669650bb0ac3e34920d09e62400";
    sha256 = "sha256-f+8zBdqKGlFFdXZ/UkSgc+HZWDfGzKyw/VjMqdwHYok=";
  };

  listeners = pkgs.fetchFromGitHub {
    owner = "ssbb";
    repo = "zmk-listeners";
    rev = "7f9c5c33418589bb563150855c5de282bb3e1f5b";
    sha256 = "sha256-oey5BXS+2sg0GnOKUFc0o/ya/ux+bR3OPvlZ05akLvY=";
  };


  myModules = [ autoLayer
                adaptKey
                tristate
                listeners
                gatedKeys
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
