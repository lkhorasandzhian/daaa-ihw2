#!/usr/bin/env python
# coding: utf-8

# In[11]:


# Import utility libraries.
import numpy as np
import pandas as pd
import matplotlib as mpl
import matplotlib.pyplot as plt
import seaborn as sns


# In[12]:


# Run if you use dark theme.
mpl.rcParams['text.color'] = 'black'
mpl.rcParams['axes.labelcolor'] = 'black'
mpl.rcParams['xtick.color'] = 'black'
mpl.rcParams['ytick.color'] = 'black'


# In[13]:


# Seaborn font size.
sns.set(font_scale=1)


# In[14]:


# Visualizer for all included sorts.
def print_sorts_comparison(test):
    for sort_type in set(test["sort_type"]):
        sort_df = test[test['sort_type'] == sort_type]
        array_types = sort_df['array_type'].unique()

        plt.figure(figsize=(20, 20))

        for array_type in array_types:
            current_data = sort_df[sort_df['array_type'] == array_type]
            plt.plot(current_data['size'], current_data['operations'], label=array_type)

        plt.title(sort_type)
        plt.xlabel('Array Size')
        plt.xticks(sort_df['size'].unique())
        plt.ylabel('Operations')
        plt.legend(labelcolor='black', prop={'size': 15})


# In[15]:


# Visualizer for all 4 types of generated arrays.
def print_arrays_comparison(test):
    array_types = test['array_type'].unique()

    fig, axes = plt.subplots(2, 2, figsize=(25, 25))

    flattened_axes = axes.flatten()

    for i in range(array_types.shape[0]):
        ax = flattened_axes[i]
        array_type = array_types[i]

        current_df = test[test['array_type'] == array_type]

        sort_types = current_df['sort_type'].unique()
        for sort_type in sort_types:
            current_df_grouped_by_sort_type = current_df[current_df['sort_type'] == sort_type]
            ax.plot(current_df_grouped_by_sort_type['size'], current_df_grouped_by_sort_type['operations'], label=sort_type)

        ax.set_title(array_type)
        ax.set_xlabel('Array Size')
        ax.set_ylabel('Operations')
        ax.legend()
        ax.plot()


# In[16]:


# Data reading from 'test_1.csv' in 'Tests' folder.
test1 = pd.read_csv('../Tests/test_counter_1.csv', sep=';', header=None)
test1.columns = ['array_type', 'size', 'sort_type', 'operations']

# Data reading from 'test_2.csv' in 'Tests' folder.
test2 = pd.read_csv('../Tests/test_counter_2.csv', sep=';', header=None)
test2.columns = ['array_type', 'size', 'sort_type', 'operations']


# In[17]:


print_sorts_comparison(test1)


# In[18]:


print_sorts_comparison(test2)


# In[19]:


print_arrays_comparison(test1)


# In[20]:


print_arrays_comparison(test2)

