# Arquivo de Configuração QMK para o seu teclado

Este arquivo `keymap.c` foi convertido da sua configuração ZMK para QMK, mantendo todas as funcionalidades solicitadas:

## Funcionalidades Implementadas
- **Tap Dance**: Tab/Esc implementado com a funcionalidade tap dance do QMK
- **Homerow Mods**: Implementados como macros Mod-Tap com configuração personalizada de tapping term
- **Tap/Hold para Caps Lock/Shift**: Usando o macro MT(MOD_LSFT, KC_CAPS)
- **Múltiplas Camadas**: _BASE, _LOWER, _UPPER, _EXTRAS e _COLEMAK
- **Controles de Mídia e RGB**: Suporte para controles de mídia e RGB
- **Encoders**: Suporte para encoders mapeados para cada camada

## Instalação
1. Copie este arquivo para a pasta `keyboards/YOUR_KEYBOARD/keymaps/YOUR_KEYMAP_NAME/keymap.c`
2. Compile o firmware com:
```bash
qmk compile -kb YOUR_KEYBOARD -km YOUR_KEYMAP_NAME
```

## Configurações Adicionais
No seu arquivo `config.h`, adicione estas definições para um comportamento mais próximo ao ZMK:

```c
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#define TAPPING_TERM 300
#define TAPPING_TERM_PER_KEY
```

## Adaptações Realizadas
1. ZMK usa "behaviors" enquanto QMK usa combinações de:
   - Tap Dance
   - Mod-Tap
   - Layer-Tap
   
2. Homerow mods do ZMK foram traduzidos para macros QMK como `LGUI_T(KC_A)`

3. RGB foi implementado usando funções nativas do QMK

4. A camada Extras contém funções similares às de Bluetooth do ZMK, mas adaptadas para RGB e reset no QMK


### Commands

compile
```
qmk compile -kb crkbd/rev1 -km crkbd_clover
```

flash each side

```
qmk flash -kb crkbd/rev1 -km crkbd_clover -bl avrdude-split-left
qmk flash -kb crkbd/rev1 -km crkbd_clover -bl avrdude-split-right
```