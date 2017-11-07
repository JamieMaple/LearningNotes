# notes for TS

### Type annotations

  1. parameters for function: `:string`
  1. boolean number string Array: number[] / Array<number>
  1. tuple: [number, string]
  1. enum
  1. any
  1. void
  1. null
  1. never

### Interfaces
  exp
  
    ```
      interface Person {
        firstName: string;
        lastName: string;
      }
    ```
  
  1. `?` for optional properties
  1. `readonly` prefiex to be not changed
  1. `ReadonlyArray`

### Classes
  exp

    ```
      class Student {
        fullName: string;
        constructor(public firstName: string, public middleInitial: string, public lastName: string) {
              this.fullName = firstName + " " + middleInitial + " " + lastName;
          }
      }
    ```
### functional Programming and OOP
