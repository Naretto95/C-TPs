# TP8 — Classic Ciphers

Three historical ciphers, selected via a command-line argument:

| Argument | Cipher | Description |
| --- | --- | --- |
| `cesar` | Caesar cipher | Shifts each letter by a fixed amount. |
| `vigenere` | Vigenere cipher | Shifts each letter by an amount derived from a repeating key. |
| `scytale` | Scytale cipher | Columnar transposition, as if wrapped around a rod. |

## Build & run

```sh
make
./bin/tp8 cesar
./bin/tp8 vigenere
./bin/tp8 scytale
make clean
```

Each mode then prompts interactively for the word to encode (and a shift or
key, where relevant). See [Rapport.pdf](Rapport.pdf) for the original lab report.
