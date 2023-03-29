import matplotlib.pyplot as plt

# Input size
sizeOfInput = [10000, 20000, 30000, 40000, 60000, 100000]

# Time taken by various sorting algorithms
bubbleSort = [0, 1, 4, 7, 17, 51]
insertionSort = [0, 0, 1, 2, 4, 16]
selectionSort = [0, 0, 1, 3, 7, 22]
mergeSort = [0, 0, 0, 2, 5, 21]
quickSort = [0, 0, 0, 0, 0, 0]

# Plot the data
plt.plot(sizeOfInput, bubbleSort, label="Bubble Sort")
plt.plot(sizeOfInput, insertionSort, label="Insertion Sort")
plt.plot(sizeOfInput, selectionSort, label="Selection Sort")
plt.plot(sizeOfInput, mergeSort, label="Merge Sort")
plt.plot(sizeOfInput, quickSort, label="Quick Sort")

# Add labels and title
plt.xlabel("Input Size")
plt.ylabel("Time Taken (s)")
plt.title("Comparison of Sorting Algorithms")

# Add legend
plt.legend()

# Display the plot
plt.show()
