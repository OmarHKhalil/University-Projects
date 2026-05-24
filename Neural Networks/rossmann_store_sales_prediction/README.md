
# Rossmann Store Sales Prediction (Deep Learning Pipeline)

A robust, production-grade Deep Learning regression pipeline built using **TensorFlow, Keras, and Scikit-Learn** to forecast daily sales for Rossmann drug stores up to six weeks in advance. 

This project explores the architectural evolution of Multi-Layer Dense Neural Networks (MLPs), benchmarking six different network topologies to model complex retail dynamics—including promotional campaigns, competition longevity, school/state holidays, and structural seasonal patterns.

---

## 📊 Dataset & Problem Statement

Rossmann operates over 3,000 stores across 7 European countries. Predicting daily sales accurately is a high-dimensional challenge influenced by overlapping localized factors. The objective is to forecast the `Sales` column for the test set using historical data from 1,115 stores.

### Data Engineering & Merging
The raw dataset comprises individual store attributes (`store.csv`) and historical transaction ledgers (`train.csv` / `test.csv`). These data sources were left-merged on the unique `Store` identifier to form a holistic feature space:
```python
merged_df = ross_df.merge(store_df, how='left', on='Store')
merged_test_df = test_df.merge(store_df, how='left', on='Store')

```

---

## 🛠️ Data Preprocessing & Feature Engineering

To feeding raw data into deep neural networks, a specialized tabular preprocessing pipeline was implemented:

1. **Temporal Deconstruction:** The raw `Date` object was parsed into structured numerical dimensions: `Year`, `Month`, `Day`, and `WeekOfYear`.
2. **Structural Data Purging:** Outliers where stores were temporarily closed (`Open == 0`) were filtered out, as they generate deterministic zero sales which bias statistical optimization.
3. **Competition Longevity Indexing:** Combined raw year and month columns into a continuous dynamic metric tracking the total consecutive months a competitor has been active nearby:

$$\text{CompetitionOpen} = 12 \times (\text{Year} - \text{CompetitionOpenSinceYear}) + (\text{Month} - \text{CompetitionOpenSinceMonth})$$


4. **Missing Value Imputation:** Missing fields in `CompetitionDistance` were filled with an adversarial placeholder value ($\text{max\_distance} \times 2$) to indicate extreme isolation.
5. **Feature Scaling & Encoding:** * **Numerical Columns:** Rescaled strictly between $[0, 1]$ utilizing `MinMaxScaler`.
* **Categorical Columns:** Expanded into binary vector spaces via `OneHotEncoder(sparse_output=False)`.



---

## 🏗️ Neural Network Architecture Evolution

Six different Multi-Layer Perceptron (MLP) variants were built and evaluated using Dense layers with **ReLU** hidden activations and a **Linear** output node, optimized via Mean Squared Error (**MSE**) loss.

### Model Performance Benchmarking Matrix

The models were evaluated using the Coefficient of Determination ($R^2$ Score) and Mean Absolute Error (MAE) across the Train, Validation, and Test splits:

| Model ID | Architectural Blueprint | Epochs / Batch Size | Train $R^2$ | Val $R^2$ | Test $R^2$ | Final Test MAE |
| --- | --- | --- | --- | --- | --- | --- |
| **Model 1** | 3x Hidden (150-150-150) | 10 / 64 | 0.5226 | 0.5172 | 0.5187 | 1563.08 |
| **Model 2** | 5x Hidden (150-150-150-150-150) | 15 / 64 | 0.8278 | 0.8212 | 0.8225 | 902.21 |
| **Model 3** | 2x Wide Hidden (350-350) | 15 / 64 | 0.4582 | 0.4557 | 0.4545 | 1641.76 |
| **Model 4** | 3x Wide (350-350-350) + Batch Normalization + Dropout (0.3) | 50 / 64 (Early Stop) | 0.7743 | 0.7758 | 0.7710 | 1027.03 |
| **Model 5** | **5x Wide Hidden (350-350-350-350-350)** | **15 / 64** | **0.8658** | **0.8614** | **0.8593** | **809.97** |
| **Model 6** | Funnel Network (350 $\rightarrow$ 256 $\rightarrow$ 128 $\rightarrow$ 64) + Dropout | 15 / 64 | 0.5513 | 0.5470 | 0.5480 | 1487.05 |

---

## 🏆 Key Findings & Conclusion

* **Winner Architecture:** **Model 5** achieved the highest performance across all evaluation horizons ($R^2 = 0.8593$ on unseen test data) and minimized the average deviation to **809.97 €** per daily store transaction.
* **Capacity Matters:** Deeper and wider structures drastically improved the model's capacity to recognize multi-level interaction terms (e.g., how the presence of a promo scales sales relative to historical competitor distances).
* **Generalization Stability:** The tight bounds between Training, Validation, and Testing performance indices across all models verify a highly stable split strategy and successful feature stabilization.

---

## 💻 How to Execute the Jupyter Notebook

### Dependencies & Setup

Ensure you have Python 3.10+ and the required native ML packages installed:

```bash
pip install tensorflow pandas numpy scikit-learn seaborn matplotlib opendatasets

```

### Run Pipeline

1. Clone your overarching repository and move into this directory.
2. Execute the notebook components sequentially.
3. The `opendatasets` module will prompt for your Kaggle API credentials (`kaggle.json`) to download the source dataset automatically.

```python
import tensorflow as tf
# Verify hardware accelerator deployment
print("Num GPUs Available: ", len(tf.config.list_physical_devices('GPU')))

```
