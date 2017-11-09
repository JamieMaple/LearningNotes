const gulp = require('gulp')

gulp.task('hello', () => {
  console.log('hello world')
})

gulp.task('world', () => {
  console.log('world')
})

gulp.task('default', ['hello', 'world'], function () {
  return gulp.dest('dist')
})
