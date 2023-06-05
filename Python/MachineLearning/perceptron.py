import numpy as np
import matplotlib.pyplot as plt

class Perceptron:
    def __init__(self, input_size, learning_rate=0.1, max_epochs=100):
        self.weights = np.zeros(input_size + 1)
        self.learning_rate = learning_rate
        self.max_epochs = max_epochs

    def predict(self, inputs):
        summation = np.dot(inputs, self.weights[1:]) + self.weights[0]
        activation = 1 if summation > 0 else 0
        return activation

    def train(self, training_inputs, labels):
        epoch_errors = []
        for _ in range(self.max_epochs):
            errors = 0
            for inputs, label in zip(training_inputs, labels):
                prediction = self.predict(inputs)
                self.weights[1:] += self.learning_rate * (label - prediction) * inputs
                self.weights[0] += self.learning_rate * (label - prediction)
                errors += int(label != prediction)
            epoch_errors.append(errors)
            if errors == 0:
                break

        plt.plot(range(1, len(epoch_errors) + 1), epoch_errors)
        plt.xlabel('Epoch')
        plt.ylabel('Number of Errors')
        plt.title('Training Error Progress')
        plt.show()

# 테스트를 위한 입력 데이터와 레이블을 정의합니다.
training_inputs = np.array([[0, 0], [0, 1], [1, 0], [1, 1], [0, 1], [1, 0], [0, 0], [1, 1], [1, 0], [0, 1]])
labels = np.array([0, 1, 1, 0, 1, 1, 0, 0, 1, 1])

# Perceptron 객체를 생성하고 학습합니다.
perceptron = Perceptron(input_size=2)
perceptron.train(training_inputs, labels)

# 새로운 입력에 대한 예측을 수행합니다.
inputs = np.array([1, 0])
print(perceptron.predict(inputs))  # 출력: 1