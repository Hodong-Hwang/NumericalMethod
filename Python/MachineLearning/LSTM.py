import numpy as np
from keras.models import Sequential
from keras.layers import LSTM, Dense

# Generate some sample data
data = np.random.randn(1000, 20, 1)
targets = np.random.randint(2, size=(1000, 1))

# Split data into training and testing sets
train_data = data[:800]
train_targets = targets[:800]
test_data = data[800:]
test_targets = targets[800:]

# Define the model architecture
model = Sequential()
model.add(LSTM(32, input_shape=(20, 1)))
model.add(Dense(1, activation='sigmoid'))

# Compile the model
model.compile(loss='binary_crossentropy', optimizer='rmsprop', metrics=['accuracy'])

# Train the model
model.fit(train_data, train_targets, epochs=10, batch_size=16, validation_data=(test_data, test_targets))