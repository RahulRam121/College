struct Stack {
    int top = -1;
    int capacity = 20;
    char array[20][5];
};

// Stack is full when top is equal to the last index
bool isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1 ? true : false;
}
 
// Stack is empty when top is equal to -1
bool isEmpty(struct Stack* stack)
{
    return stack->top == -1 ? true : false;
}
 
// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, char item[])
{
    if (isFull(stack))
        return;
    strcpy(stack->array[++stack->top], item);
}
 
// Function to remove an item from stack.  It decreases top by 1
char* pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}
 
// Function to return the top from stack without removing it
char* peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}
 
// Driver program to test above functions
int main()
{
    struct Stack* stack = createStack(100);
 
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
 
    printf("%d popped from stack\n", pop(stack));
 
    return 0;
}
