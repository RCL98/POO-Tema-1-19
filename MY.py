import numpy as np
import matplotlib.pyplot as plt
train_images = np.loadtxt("train_images.txt")
train_labels = np.loadtxt("train_labels.txt")
test_images = np.loadtxt("test_images.txt")
test_labels = np.loadtxt("test_labels.txt")


class KnnClasifier:
    def __init__(self, train_images, train_labels, metric="l2"):
        self.train_images = train_images
        self.train_lebels = train_labels

    def clasify_image(self, test_image, metric="l2", num_neighbors=3):
        norm_vector = []
        if (metric == "l2"):
            norm_vector = np.sqrt(np.sum((self.train_images - test_image) ** 2, axis=1))
        else:
            if (metric == "l1"):
                norm_vector = np.sqrt(np.sum(abs(self.train_images - test_images), axis=1), dtype=np.int64)

        index_sort = np.argsort(norm_vector)
        k_index = index_sort[:num_neighbors]
        et_priority = np.array(train_labels[k_index], dtype=np.int)
        frec_et = np.bincount(et_priority)
        return np.argmax(frec_et)

    def clasify_images(self, test_images, metric="l2", num_neighbors=3):
        return [self.clasify_image(test_images[i], metric, num_neighbors) for i in range(np.shape(test_images)[0])]


my_model = KnnClasifier(train_images, train_labels, "l2")
num_neigh = [1, 3, 5, 7, 9]
accuracy = []

for neigh in num_neigh:
    my_est = my_model.clasify_images(test_images, "l2", neigh)
    loc_accuracy = np.sum([(test_labels[i] == my_est[i]) for i in range(np.shape(my_est)[0])]) / np.shape(my_est)[0]
    accuracy.append(loc_accuracy)

plt.plot(num_neigh, accuracy)
plt.show()
