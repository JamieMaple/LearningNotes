interface Person {
  firstName: string
  lastName: string
}

class Student {
  fullName: string;
  constructor(private firstName: string, public middleInitial: string, public lastName: string) {
      this.fullName = firstName + " " + middleInitial + " " + lastName;
  }
}

function greeter(person : Person) {
  return 'Hello, ' + ' ' + person.lastName + '.'
}

export default greeter
