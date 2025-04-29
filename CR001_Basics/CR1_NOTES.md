
----

## 1. **`errno`**:  
This is a global variable set by system calls and library functions when they encounter an error. It holds the error code, which is an integer corresponding to a specific error condition.

```c
int error_code = errno;  // Store the current errno value
```

---

## 2. **Error Codes in `errno.h`**:  
`errno.h` defines a bunch of constants that describe different types of errors. These constants can be checked manually to handle specific errors.

Some common error codes include:
- **`ENOMEM`**: Out of memory.
- **`EIO`**: I/O error.
- **`EINVAL`**: Invalid argument.
- **`ENOENT`**: No such file or directory.
- **`EAGAIN`**: Try again (resource temporarily unavailable).

Example:
```c
#include <errno.h>
#include <stdio.h>

if (some_func() == -1) {
    if (errno == ENOMEM) {
        printf("Out of memory\n");
    }
    else if (errno == EIO) {
        printf("I/O error occurred\n");
    }
}
```

---

## 3. **`strerror()`**:  
This function takes an `errno` value and returns a pointer to a string describing the error. It's often used to convert an error number into a human-readable string.

```c
#include <stdio.h>
#include <string.h>
#include <errno.h>

if (some_func() == -1) {
    printf("Error: %s\n", strerror(errno));  // Human-readable error message
}
```

For example:
```c
if (fopen("non_existent_file.txt", "r") == NULL) {
    printf("Error: %s\n", strerror(errno)); // Prints: Error: No such file or directory
}
```

---

## 4. **`perror()`**:  
As you already know, this function is the easiest way to print the error message corresponding to the current value of `errno`.

```c
perror("Error in function X");
```

This prints something like:
```
Error in function X: No such file or directory
```
### Do we need `\n` inside `perror()`?

**No**, you do **not** need to add a newline manually.  
`perror()` automatically prints the error message **followed by a newline**.

✅ Correct:
```c
perror("Error");
```

🚫 Avoid:
```c
perror("\nError");  // Adds unnecessary newlines
```
---

## 5. **`clearerr()`**:  
Although not exactly related to `errno`, `clearerr()` is used to clear the error and EOF flags for a file stream.

```c
FILE *file = fopen("file.txt", "r");

if (file == NULL) {
    perror("File open failed");
    clearerr(file);  // Clears any error flags for the file
}
```

---

## Summary of Key Functions/Features in `errno.h`:
- **`errno`**: The global variable that holds the error code.
- **`perror()`**: Prints an error message based on `errno`.
- **`strerror()`**: Converts an error code (`errno`) into a human-readable string.
- **Error codes**: Constants like `ENOMEM`, `EINVAL`, etc., to check specific error conditions.
- **`clearerr()`**: Clears error and EOF flags for file streams.

---
