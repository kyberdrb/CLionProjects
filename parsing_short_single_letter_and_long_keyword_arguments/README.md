Correct

```sh
./cmake-build-debug/parsing_short_single_letter_and_long_keyword_arguments -p milliseconds -d -? -- -unakkum -enakkum
```

Error

```sh
./cmake-build-debug/parsing_short_single_letter_and_long_keyword_arguments -p milliseconds -d -? -unakkum -enakkum
```

Correct

```sh
./cmake-build-debug/parsing_short_single_letter_and_long_keyword_arguments -p milliseconds -d -?
```