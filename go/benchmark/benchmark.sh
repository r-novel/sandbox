#!/bin/bash

GO=/usr/local/go/bin/go

$GO test -bench=. -benchmem *_test.go
