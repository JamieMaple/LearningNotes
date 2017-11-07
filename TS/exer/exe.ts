interface Person {
  readonly firstName: string;
  readonly lastName: string;
}

let myName: string = 'kevin'
let age: number = 40
let vanVote: boolean = true
let anything: any = 2
let test: string | null | undefined = 'sdsfsdf'
enum Color {red, green, yellow}

Color[0]
Color['red']

anything = 'dog'
test = null
