package main

import (
	. "gopkg.in/check.v1"
	"testing"
)

func Test(t *testing.T) { TestingT(t) }

type CheckSuite struct{}

var _ = Suite(&CheckSuite{})

func (s *CheckSuite) TestCheckSubstringTrue(c *C) {
	c.Check(SubstringCheck("Hello world", "wor"), Equals, true)
	c.Check(SubstringCheck("XYxU v", "xU"), Equals, true)
	c.Check(SubstringCheck("ABCDEFG", "ABC"), Equals, true)
}

func (s *CheckSuite) TestCheckSubstringFalse(c *C) {
	c.Check(SubstringCheck("Hello world", "ddd"), Equals, false)
	c.Check(SubstringCheck("XYxU v", "XX"), Equals, false)
	c.Check(SubstringCheck("ABCD", "abc"), Equals, false)
	c.Check(SubstringCheck("ABCD E", "BCD E"), Equals, false)
	c.Check(SubstringCheck("ABCDE", "ABCDEF"), Equals, false)
}
