# My KEYMAP

## Keymap
![keymap](https://user-images.githubusercontent.com/1324680/37965113-e6ca9f26-31fe-11e8-8b5b-b0d414ff6a6d.png)

## Build
### for Mac
1. ``` brew tap osx-cross/avr ```
2. ``` brew install avr-gcc ```
3. Change path to Project Directory
4. ``` make ergodox_ez:teitei-tk ```
5. Captcha ./keymap.c
6. ``` python -c "import base64; print(base64.b64encode(open('./keymap.png', 'rt').read()))" ```
7. update keymap base64 data
