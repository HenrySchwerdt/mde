package main

import (
	"flag"
)

func main() {
	editFile := flag.String("e", "test.boo", "input file to edit")
	flag.Parse()
	if editFile != nil {
		ui := mdeterm.newUI()
	}
}
