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
            errors=errors/(len(labels)-1)
            
            epoch_errors.append(errors)
            if errors == 0:
                break

        plt.plot(range(1, len(epoch_errors) + 1), epoch_errors)
        plt.xlabel('Epoch')
        plt.ylabel('Error Rate')
        plt.title('Training Error Progress')
        plt.show()

# 선형 데이터 생성
np.random.seed(0)
num_samples = 100
mean_class1 = [2, 2]
mean_class2 = [4, 4]
cov_class1 = [[0.3, 0.2], [0.2, 0.3]]
cov_class2 = [[0.3, 0.2], [0.2, 0.3]]
class1_samples = np.random.multivariate_normal(mean_class1, cov_class1, num_samples)
class2_samples = np.random.multivariate_normal(mean_class2, cov_class2, num_samples)

# 데이터 시각화
plt.scatter(class1_samples[:, 0], class1_samples[:, 1], marker='o', label='Class 1')
plt.scatter(class2_samples[:, 0], class2_samples[:, 1], marker='x', label='Class 2')
plt.xlabel('X')
plt.ylabel('Y')
plt.legend()
plt.title('Linear Data')
plt.show()

# 학습 데이터와 레이블 생성
training_inputs = np.vstack((class1_samples, class2_samples))
labels = np.hstack((np.zeros(num_samples), np.ones(num_samples)))

# Perceptron 객체를 생성하고 학습합니다.
perceptron = Perceptron(input_size=2)
perceptron.train(training_inputs, labels)

# 새로운 입력에 대한 예측을 수행합니다.
inputs = np.array([3, 3])
print(perceptron.predict(inputs))  # 출력: 1