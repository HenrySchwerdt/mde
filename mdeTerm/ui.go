package mdeterm

import (
	"io"
	"os"
)

type UI struct {
	Writer io.Writer
	Reader io.Reader
}

func NewUI() *UI {
	return &UI{
		Writer: os.Stdout,
		Reader: os.Stdin,
	}
}

func (ui *UI) ReadInputByte() (string, error) {
	var rBuf []byte
	var err error
	for {
		var buf [1]byte
		_, err = ui.Reader.(*os.File).Read(buf[:])
		if err != nil && err != io.EOF {
			break
		}
		rBuf = append(rBuf, buf[0])
		if len(rBuf) > 0 {
			break
		}
	}
	return string(rBuf), err
}
