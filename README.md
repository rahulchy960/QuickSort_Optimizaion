# 🚀 QuickSort Comparison: Basic vs Optimized

This repository contains two implementations of **QuickSort in C++**:

1. **Basic QuickSort (Lomuto)**  
   - Uses the **Lomuto partition scheme** (pivot = last element).  
   - Simple recursive implementation.  
   - Degrades to `O(n^2)` on sorted or adversarial inputs.  

2. **Optimized QuickSort**  
   - Uses **3-way partitioning (Dutch National Flag)** for efficient handling of duplicates.  
   - Uses **tail recursion elimination** to reduce stack depth.  
   - Performs significantly better on datasets with many duplicates.  

---