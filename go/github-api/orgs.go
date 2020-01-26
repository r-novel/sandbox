package main

import (
	"context"
	"fmt"

	"github.com/google/go-github/v29/github"
)

// Fetch all the public organizations' membership of a user.
func fetchOrganizations(username string) ([]*github.Organization, error) {
	client := github.NewClient(nil)
	orgs, _, err := client.Organizations.List(context.Background(), username, nil)
	return orgs, err
}

func main() {
	var username string
	fmt.Print("Enter GitHub username: ")
	fmt.Scanf("%s", &username)

	organizations, err := fetchOrganizations(username)
	if err != nil {
		fmt.Printf("error with fetch: %v\n", err)
		return
	}

	for i, organization := range organizations {
		fmt.Printf("%v. %v\n", i+1, organization.GetLogin())
	}
}
