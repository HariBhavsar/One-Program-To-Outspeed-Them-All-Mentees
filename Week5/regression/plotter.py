import subprocess
import matplotlib.pyplot as plt

# Function to run the binary and capture output
def run_binary_and_capture_output():
    # Run the binary and capture its output
    process = subprocess.Popen(['./main'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    with open('regression_data.csv', 'r') as infile:
        stdout, stderr = process.communicate(input=infile.read().encode())
    
    return stdout.decode()

# Function to process the captured output
def process_output(output):
    # print(output)
    # Split the output into two parts: before and after the separator
    before_separator, after_separator = output.split('===========================================', 1)
    # print(before_separator)
    # Extract training loss data
    training_loss_line = before_separator.split('\n')[0]  # Assuming it's the first line
    # print(before_separator.split('\n')[1:len(before_separator.split('\n'))-2])
    training_loss_values = [float(x) for x in before_separator.split('\n')[1:len(before_separator.split('\n'))-2]]  # Skip the 'Training loss' part
    # print("training loss line : ",training_loss_line,"and training loss values",training_loss_values)
    return training_loss_values, after_separator

# Function to plot the training loss data
def plot_training_loss(training_loss_values):
    # print(training_loss_values)
    plt.plot(training_loss_values)
    plt.xlabel('Iteration')
    plt.ylabel('Training Loss')
    plt.title('Training Loss Over Iterations')
    plt.show()
    plt.savefig("graph.png")

# Function to save the remaining output to a text file
def save_remaining_output(after_separator):
    with open('out.txt', 'w') as outfile:
        outfile.write(after_separator)

# Main function
def main():
    output = run_binary_and_capture_output()
    training_loss_values, after_separator = process_output(output)
    plot_training_loss(training_loss_values)
    save_remaining_output(after_separator)

if __name__ == '__main__':
    main()
