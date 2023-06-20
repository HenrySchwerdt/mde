package main

import (
	"flag"
	"mde/editor"
	"mde/mdeterm"
)

func main() {
	editFile := flag.String("e", "test.boo", "input file to edit")
	flag.Parse()
	if editFile != nil {
		ui := mdeterm.NewUI()
		buffer := editor.NewBuffer(ui, editFile)
		buffer.Load()
		buffer.SetFocus()
	}
}
