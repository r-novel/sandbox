package main

type Option struct {
	Short         string
	Long          string
	Description   string
	IsRequiredVal bool
}

type Options []*Option

func Parse(Args []string) {

}

func main() {
	opt := Option{"h", "help", "Print usage message", false}
	// Parse(os.Args)
}
