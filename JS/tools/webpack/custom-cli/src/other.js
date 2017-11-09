import bar from './test'

bar('bar123')

export default function foo(name = 'foo') {
  console.log(name)
}
