#include<iostream>
#include<string>
// Define a struct for a node in the linked list
struct node
{
	std::string url;   // Holds the URL
	node* next, * prev;
	node()	
	{
		next = nullptr;
		prev = nullptr;
	}
};
// Define a class for browser history
class BrowserHistory
{
private:
	node* current;
	int size;
public:
	BrowserHistory(std::string url)
	{
		current = new node;
		current->prev = nullptr;
		current->next = nullptr;
		current->url = url;
	}
	// Function to get the current URL
	std::string Current()
	{
		return current->url;
	}
	// Function to visit a new URL
	void visit(const std::string& url)
	{
		node* temp = new node;
		temp->prev = current;
		current->next = temp;
		temp->url = url;
		temp->next = nullptr;
		current = temp;
	}
	// Function to navigate back by a certain number of steps
	std::string back(int step)
	{
		for (int i = 0; i < step; i++)
		{
			if (current->prev == nullptr)
			{
				std::cout << "Can't go back further. " << std::endl;
			}
			else
			{
				current = current->prev;
			}
		}
		return current->url;

	}
	// Function to navigate forward by a certain number of steps
	std::string forward(int step)
	{
		for (int i = 0; i < step; i++)
		{
			if (current->next == nullptr)
			{
				std::cout << "Can't go Forward more. " << std::endl;
				break;
			}
			else
			{
				current = current->next;
			}
		}
		return current->url;
	}
};
int main()
{
	// Create an instance of BrowserHistory and initialize it with a homepage URL
	BrowserHistory *b1 = new BrowserHistory("homepage.com");
	// Visit some URLs
	b1->visit("site1.com");
	b1->visit("site2.com");
	b1->visit("site3.com");
	b1->visit("site4.com");

	// Go back by 3 steps and print the current URL
	std::cout<<"Current URL is "<<b1->back(3)<<std::endl;

	// Go forward by 3 steps and print the current URL
	std::cout<<"Current URL is "<< b1->forward(3) <<std::endl;

	// Visit another URL and print the current URL
	b1->visit("site5.com");
	std::cout << "Current URL is " << b1->Current() << std::endl;
}