const { should: shouldTmp, expect } = require('chai')
const { sum, mul } = require('../main')
const should = shouldTmp()

describe('二元运算', function() {
  describe('#sum', function() {
    it('1 + 10 = 11', function() {
      const result = sum(1)(10)
      expect(result).to.equal(11, '1 + 10 = 11')
    })
  })
  describe('#mul', function() {
    it('2 * 11 = 22', function() {
      const result = mul(2)(11)
      result.should.equal(22, '2 * 11 = 22')
    })
  })
})

describe('async', function() {
  it('#after time', function(done) {
    setTimeout(() => {
      done()
    }, 500)
  })
})
