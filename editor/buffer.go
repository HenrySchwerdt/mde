package editor

import (
	"bufio"
	"fmt"
	"log"
	mdeterm "mde/mdeTerm"
	"os"
	"strings"
)

type Buffer struct {
	ui       *mdeterm.UI
	filePath *string
	data     []string
}

func NewBuffer(ui *mdeterm.UI, filePath *string) *Buffer {
	return &Buffer{
		ui:       ui,
		filePath: filePath,
		data:     make([]string, 0),
	}
}

func (buffer *Buffer) Load() {
	fh, err := os.Open(*buffer.filePath)

	if err != nil {
		log.Fatal(err)
	}
	scanner := bufio.NewScanner(fh)

	for scanner.Scan() {
		buffer.data = append(buffer.data, scanner.Text())
	}
	fmt.Println(buffer.GetData())
}

func (buffer *Buffer) GetData() string {
	return strings.Join(buffer.data, "")
}
