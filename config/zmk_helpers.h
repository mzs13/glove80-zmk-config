#pragma once


#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/ext_power.h>
#include <dt-bindings/zmk/outputs.h>
#include <dt-bindings/zmk/rgb.h>
#include <dt-bindings/zmk/mouse.h>

#define ___ &trans
#define _x_ &none



#define ALL_LAYERS 

#define NO_DOUBLE       (-1)
#define FAST_DOUBLE     100
#define MED_DOUBLE      150
#define SLOW_DOUBLE     200
#define SSLOW_DOUBLE    300

#define FAST_TD         250
#define MED_TD          300
#define SLOW_TD         350
#define SSLOW_TD        400

#define FAST_COMBO      30
#define MED_COMBO       80
#define SLOW_COMBO      150
#define SSLOW_COMBO     200

#define FAST_HOLD       150
#define MED_HOLD        200
#define SLOW_HOLD       325
#define SSLOW_HOLD      450

#define NO_QUICK_TAP    (-1)
#define NO_IDLE         (-1)
#define ALL_POSITIONS
#define NO_RETRO
#define RETRO           retro-tap;

#define NORMAL_RELEASE
#define SLOW_RELEASE    slow-release;





#define DEFZ 	/
#define COMBOZ 	combos
#define BEHAVIORZ 	behaviors
#define MACROZ 	macros
#define COND_LAYERZ auto_layers
#define LAYERZ	layers


DEFZ { COMBOZ { compatible = "zmk,combos"; }; };
DEFZ { COND_LAYERZ { compatible = "zmk,conditional-layers"; }; };
DEFZ { LAYERZ { compatible = "zmk,keymap"; }; };


//----------------------------------------------------------------------------
//Combos


//optional args
// RELEASE_TYPE - NORMAL_RELEASE | SLOW_RELEASE
// PRIOR_IDLE - time in ms
#define ZCOMBO( NAME, KEYPOS, BINDS, TIMEOUT, LAYERS, ... )  DYN_MACRO_CALL( ZCOMBO, NAME, KEYPOS, BINDS, TIMEOUT, EXPAND_LAYERS(LAYERS), ##__VA_ARGS__ )


#define EXPAND_LAYERS(...) DYN_MACRO_CALL(EXPAND_LAYERS, ##__VA_ARGS__)
#define EXPAND_LAYERS0()
#define EXPAND_LAYERS1(LAYERS) layers = <LAYERS>;


#define ZCOMBO5( NAME, KEYPOS, BINDS, TIMEOUT, LAYERS ) ZCOMBO6( NAME, KEYPOS, BINDS, TIMEOUT, LAYERS, SLOW_RELEASE )
#define ZCOMBO6( NAME, KEYPOS, BINDS, TIMEOUT, LAYERS, RELEASE ) ZCOMBO7( NAME, KEYPOS, BINDS, TIMEOUT, LAYERS, RELEASE, NO_IDLE )
#define ZCOMBO7( NAME, KEYPOS, BINDS, TIMEOUT, LAYERS, RELEASE, IDLE ) \
    NAME {  \
        timeout-ms = <TIMEOUT>; \
        key-positions = <KEYPOS>; \
        bindings = <BINDS>; \
        require-prior-idle-ms = <IDLE>; \
        LAYERS \
        RELEASE \
    };




//----------------------------------------------------------------------------
//  Behaviors

#define ZHOLD_TAP( NAME, HOLD, TAP, FLAVOR, TAPTERM, ... )  DYN_MACRO_CALL( ZHOLD_TAP, NAME, HOLD, TAP, FLAVOR, TAPTERM, ##__VA_ARGS__ )

#define ZHOLD_TAP5( NAME, HOLD, TAP, FLAVOR, TAPTERM ) 			ZHOLD_TAP6( NAME, HOLD, TAP, FLAVOR, TAPTERM, NO_QUICK_TAP )
#define ZHOLD_TAP6( NAME, HOLD, TAP, FLAVOR, TAPTERM, QUICKTAP ) 		ZHOLD_TAP7( NAME, HOLD, TAP, FLAVOR, TAPTERM, QUICKTAP, ALL_POSITIONS )
#define ZHOLD_TAP7( NAME, HOLD, TAP, FLAVOR, TAPTERM, QUICKTAP, HOLD_POSITIONS ) 	ZHOLD_TAP8( NAME, HOLD, TAP, FLAVOR, TAPTERM, QUICKTAP, HOLD_POSITIONS, NO_IDLE )
#define ZHOLD_TAP8( NAME, HOLD, TAP, FLAVOR, TAPTERM, QUICKTAP, HOLD_POSITIONS, IDLE ) 	ZHOLD_TAP9( NAME, HOLD, TAP, FLAVOR, TAPTERM, QUICKTAP, HOLD_POSITIONS, IDLE, NO_RETRO )
#define ZHOLD_TAP9( NAME, HOLD, TAP, FLAVOR, TAPTERM, QUICKTAP, HOLD_POSITIONS, IDLE, RETRO ) \
    NAME: _##NAME##_ { \
        compatible = "zmk,behavior-hold-tap"; \
        #binding-cells = <2>; \
        flavor = #FLAVOR; \
        tapping-term-ms = <TAPTERM>; \
        quick-tap-ms = <QUICKTAP>; \
        require-prior-idle-ms = <IDLE>; \
        bindings = <HOLD>, <TAP>; \
        hold-trigger-key-positions = <HOLD_POSITIONS>; \
        RETRO \
    };


#define ZTAP_DANCE2( NAME, FIRST, SECOND, TAPTERM) \
    NAME: _##NAME##_ { compatible = "zmk,behavior-tap-dance"; #binding-cells = <0>; tapping-term-ms = <TAPTERM>; bindings = <FIRST>, <SECOND>; };

#define ZTAP_DANCE3( NAME, FIRST, SECOND, THIRD, TAPTERM) \
    NAME: _##NAME##_ { compatible = "zmk,behavior-tap-dance"; #binding-cells = <0>; tapping-term-ms = <TAPTERM>; bindings = <FIRST>, <SECOND>, <THIRD>; };



#define ZMOD_MORPH( NAME, MODS, PRESS, MOD_PRESS ) \
    NAME: _##NAME##_ { compatible = "zmk,behavior-mod-morph"; #binding-cells = <0>; bindings = <PRESS>, <MOD_PRESS>; mods = <(MODS)>; keep-mods = <0>;};

//(MT), (sk)
#define ZSMOD_TAP_DANCE( NAME, MT, MOD, TAP, TAPTERM) ZTAP_DANCE2( NAME, MT MOD TAP, &sk MOD, TAPTERM )
//(mo) / (tog)
#define ZTD_MOTOG( NAME, LAYER, DOUBLE_SPD) ZTAP_DANCE2( NAME, &mo LAYER, &tog LAYER, DOUBLE_SPD )
//(sl) / (tog)
#define ZTD_SLTOG( NAME, LAYER, DOUBLE_SPD) ZTAP_DANCE2( NAME, &sl LAYER, &tog LAYER, DOUBLE_SPD )
//(LT) / (tog)
#define ZTD_LTTOG( NAME, LT, LAYER, TAP, TAPTERM) ZTAP_DANCE2( NAME, LT LAYER TAP, &tog LAYER, TAPTERM )




//----------------------------------------------------------------------------
// Macros



#define ZMACRO0( NAME, COMMANDS...) \
    NAME: _##NAME##_ { compatible = "zmk,behavior-macro"; #binding-cells = <0>; wait-ms = <30>; tap-ms = <40>; bindings = COMMANDS; };

#define ZMACRO1( NAME, COMMANDS...) \
    NAME: _##NAME##_ { compatible = "zmk,behavior-macro-one-param"; #binding-cells = <1>; wait-ms = <30>; tap-ms = <40>; bindings = COMMANDS; };

#define ZMACRO2( NAME, COMMANDS...) \
    NAME: _##NAME##_ { compatible = "zmk,behavior-macro-two-param"; #binding-cells = <2>; wait-ms = <30>; tap-ms = <40>; bindings = COMMANDS; };



//----------------------------------------------------------------------------
// Conditional Layers

#define ZCOND_LAYER( NAME, ONLAYER, IFLAYERS ) \
    NAME { \
        if-layers = <IFLAYERS>; \
        then-layer = <ONLAYER>; \
    };


//----------------------------------------------------------------------------
// Leader Keys

#define ZLEADER_SEQUENCE( NAME, POSITIONS, BINDING ) \
    NAME { key-positions = <POSITIONS>; bindings = <BINDING>; };

#define ZLEADER_KEY( NAME, TIMEOUT, SEQUENCES ) \
    NAME: _##NAME##_ { \
        compatible = "zmk,behavior-leader-key"; \
        #binding-cells = <0>; \
        timeout-ms = <TIMEOUT>; \
        SEQUENCES \
    };



//----------------------------------------------------------------------------
// Keymaps

#define ZKEYMAP( NAME, KEYS ) \
    keymap_##NAME { \
        bindings = <KEYS>; \
    };



//Utility macros for internal use

#define INDEX_CALL_NAME( empty, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9, ARG10, ARG11, ... )  ARG11
#define GET_MACRO_NAME( ROOT_NAME, ... ) INDEX_CALL_NAME(,##__VA_ARGS__, ROOT_NAME##10, ROOT_NAME##9, ROOT_NAME##8, ROOT_NAME##7, ROOT_NAME##6, ROOT_NAME##5, ROOT_NAME##4, ROOT_NAME##3, ROOT_NAME##2, ROOT_NAME##1, ROOT_NAME##0 )
#define DYN_MACRO_CALL( MACRO, ... ) GET_MACRO_NAME( MACRO, ##__VA_ARGS__)( __VA_ARGS__ )


