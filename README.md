
# Monty

**This is an intepreter for monty programming language.**

**Usage**

```
monty [Monty code file]
```

- You can write any of the following monty code in the monty code file.

- `#` anything in that line will be ignored you can use it to comment the code.

  **Usage**

  ```
  # [Anything]
  ```

- `push` pushes a value to the stack.

  **Usage**

  ```
  push [Value]
  ```

- `pall` will print out all the values pushed using push `push`.

  **Usage**

  ```
  pall
  ```

- `mul` multiplies the last two numbers and sets the top element with the result.

  **Usage**

  ```
  mul
  ```

- `pint` prints the last number pushed using `push`.

  **Usage**

  ```
  pint
  ```

- `rotr` rotrates the last number to the beginning of the numbers pushed.

  **Usage**

  ```
  rotr
  ```

- `nop` does nothing.

  **Usage**

  ```
  nop
  ```

- `swap` will swap the the top two element which mean the first two pushed elements.

  **Usage**

  ```
  swap
  ```

- `pop` will remove the first pushed element from the top.

  **Usage**

  ```
  pop
  ```

- `add` will add the top two elements and sets the top element with the result.

  **Usage**

  ```
  add
  ```

- `sub` subtracts the top element with the next element and sets the top element with the result.

  **Usage**

  ```
  sub
  ```

- `div` divides the top element with the next element and sets the top element with the result.

  **Usage**

  ```
  div
  ```

- `mod` divides the top element with the next element and sets the top element with the reminder of the division

  **Usage**

  ```
  mod
  ```

- `pchar` returns the character representation of the top element if the number is between a-z or A-Z in ascii code.

  **Usage**

  ```
  pchar
  ```

- `pstr` prints the string starting at the top of the stack, followed by a new line.

  **Usage**

  ```
  pstr
  ```

- `rotl` rotrates the stack top to bottom.

  **Usage**

  ```
  rotl
  ```

