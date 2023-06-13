Data Scientist, Machine Learning Expert, Algorithm Engineer, Deep Learning Researcher — whatever your title might be, if using advanced concepts of Machine Learning is part of your career, then keeping up to date with the latest innovations is also a part of your everyday tasks. But in order to be on-top of all the latest ingenuities and truly understand how they work, we must also be familiar with the building blocks and foundations they rely on.

The field of Deep Learning is moving fast, breaking and setting new records in each and every possible metric exists. And as it evolves, it creates new fundamental concepts, allowing new architectures and concepts never seen before.

While I tend to assume all modern ML-practitioners are familiar with the basics fundamentals, such as CNN, RNN, LSTM and GAN, some of the newer ones are occasionally missed or left out. And so, this blogpost will discuss the new fundamentals — six papers I believe everyone in this field today should be familiar with.


(1) Attention Is All You Need
[Paper on arXiv]

Released in 2017 by a team from Google, this paper has revealed to the world a new neural-network block called a Transformer — and can easily be marked as one of the most significant milestones in the development of modern Deep Learning models.

Transformers allow processing of sequences in a parallel method, unlike the preceding state-of-the-art which relied heavily on types of RNNs. The latter tend to have a few major drawbacks — RNN layers have to rely on their own output values of the previous input. That causes slow training time, and also the well-known issue of vanishing/exploding gradients, causing RNNs to be inadequate to find relations between words which are too far apart in a sequence.

Transformers were able to tackle these issues by using two novel approaches — the first, they used positional-embeddings to mark the location of each element in the sequence, and the second was the use of attention, and specifically self-attention, to allow the model to learn the relations between different elements of the sequence.

Other than the transformers themselves, the paper is filled with little gems, optimizing the model. Here are my personal favorite two:

The authors strictly mention they use Layer Normalization instead of Batch Normalization. Summarizing the original Layer Normalization paper, it basically means normalization isn’t per feature over a batch, but over the entire sample (or layer), each sample by itself. The paper proves LN is better than BN in many cases, and as Geoffrey Hinton is one of the three authors, I’ll take his word for that.
Each sub-layer of the transformers in the Attention paper is wrapped by a skip-layer, or a residual-block (see image below). The idea behind this block is that given an input x, a network tries to learn some function H(x), which can be loosely written as H(x) = F(x) + x. Using the skip-layer mechanism, we force the middle layer to learn F(x), and according to the original Residual Learning layer, it converges better this way.

A residual block built of skip-layers. Taken from “Attention is All You Need”
(2) BERT: Pre-training of Deep Bidirectional Transformers for Language Understanding
[Paper on arXiv]

Released in 2019 by researchers from Google, BERT is an NLP model non-one could ignore, and took the NLP field one huge leap forward. BERT (which stands for Bidirectional Encoder Representations from Transformers) was developed using transformers, and became a live proof of the power these type of models can hold. Personally, I tend to consider “Attention is All You Need” and this paper as somewhat complementary; the first describing a more general and “theoretical” approach, and the latter uses it for a specific and well-defined task.

BERT was revolutionary for two main reasons: first, it was able to beat the state of the art results for eleven NLP tasks, and second — it was trained and designed to be used for fine-tuning, so it can be easily matched and tailor-made for any specific NLP tasks.

One of the key-factors which allowed BERT to be trained so efficiently was the use of WordPiece embeddings, which allowed the model to break down words to fragments, making the vocabulary to be learned much smaller.

(3) A Style-Based Generator Architecture for Generative Adversarial Networks
[Paper on arXiv]

This paper, published by Nvidia Labs in the end of 2018, has introduced the world to the StyleGAN model. Ever since Ian Goodfellow introduced the Generative Adversarial Networks (GANs) in 2014, many researchers have done tremendous work in improving GAN capabilities, but mostly by focusing on the discriminator, as better a better discriminator will eventually lead to a better generator. Yet, this lack of focus on the generator itself caused “… the generators continue to operate as black boxes, and despite recent efforts, the understanding of various aspects of the image synthesis process, e.g., the origin of stochastic features, is still lacking”. The idea behind StyleGAN was to allow tuning some of the features of the output image using another input (a second image) by directly affecting the generator itself.

Mixing in the style of one input with the generated second input was done in two main steps — first, the style-input was inserted to a dense network, outputting another learned vector. Second, a novel “Adaptive Instance Normalization” (AdaIN) is applied — the original-image input is normalized, and then the new style-embedding is mixed in:


But what I personally believe is the most interesting part of this paper, is how this model was trained and evaluated. Think of it for a second — there is no dataset the network can learn from. And so, what the researchers did is nothing but extraordinary data science — they understood and leveraged the data they have.

When it comes to the loss, the authors explicitly mention they used the standard GAN loss — it makes sense, as the images produced by StyleGAN should look realistic, just like any regular GAN produces. But when it comes to evaluation — meaning, the output’s style is indeed altered — they noticed what they call “feature entanglement”. They claim that since the photos the network was trained on are real, some facial features are correlated with one another — for example, long hair will usually be associated with women, beards with men, blue eyes with caucasians, etc. So they trained a classifier for about 40 such attributes, and have shown that StyleGAN generated photos with higher attribute-separability than a regular GAN.

(4) Learning Transferable Visual Models From Natural Language Supervision
[Paper on arXiv]

This paper, released in early 2021 by OpenAI, is probably one of the greatest revolutions in zero-shot classification algorithms, presenting a novel model known as Contrastive Language-Image Pre-Training, or CLIP for short.

CLIP was trained over a massive dataset of 400 million pairs of images and their corresponding captions, and has learnt to embed both images and free-text to the same embedding-space, so that the image and its free-text description will share the same latent vector. CLIP works with any image and any English text, and has demonstrated outstanding capabilities in zero-shot classification tasks.

More over, has been shown by several following works, latent vectors in CLIP space follow the arithmetic we are familiar with from NLP. Meaning, as we’ve all learnt that in Word2Vec latent space, we get Man + Queen - Woman = King, then in CLIP space we can have the same equation, but while using the words Man and Woman, and images of King and Queen.

(5) Mastering the Game of Go with Deep Neural Networks and Tree Search
[Paper on DeepMind’s site]

Released by DeepMind in early 2016, this paper has made a breakthrough in Reinforcement Learning when it presented AlphaGo — a model which defeated the European Go champion by 5 games to 0. This was the first AI ever that has defeated a human professional player in the full-sized game of Go, a feat previously thought to be at least a decade away.

AlphaGo uses Monte-Carlo Tree Search (MCTS) in order to compute its next move — meaning, it doesn’t really computes each and every node in the tree, but rather runs many simulations of the possible outcomes.

AlphaGo authors indicate they trained a Policy Gradient model which was optimized over a Supervised Learning model, which in turn learned from recorded human experts games. But this heavy network was too slow to be used in real games for running simulations over MCTS, so they had to find a replacement. They instead trained two networks — one lightweight Policy Gradient, which was far weaker, but also >1000 times faster, and a second Value Network, which predicted the value (meaning, the chances of winning) for each state in the game. That Value Network learned over self-played games played by the heavy Policy Gradient, thus learning directly from it. At each time step of a MCTS simulation, the lightweight network was used to generate a gameplay from the current state till the game ended, and the reward it received was combined with the Value Network assessment of current state in order to provide a Q-Value assessment of that state. Once all simulations terminated, AlphaGo selected the state it visited the most during these exploration simulations.


A MCTS phase of AlphaGo, taken from “Mastering the Game of Go with Deep Neural Networks and Tree Search”
In 2017, a year after this paper was published, DeepMind published a second Go-related paper, “Mastering the Game of Go without Human Knowledge”, which presented AlphaGo Zero, which was trained only using self-play, contained a single network instead of two — and beat AlphaGo 100–0.

(6) Deep Neural Networks for YouTube Recommendations
[Paper on Google Research]

Released in 2016, this paper sheds light on the architecture of Deep Learning models used for recommendations in YouTube. In many ways, the high-level architecture and methods described in this paper are used widely in the industry till today.

This paper is a classic go-to for every Recommendations-using-Deep-Learning question you can probably think of, and covers a wide range of topics such as high-level architecture, handling massive scale (using candidate generation and ranking models), classification as extreme multi-class classification, optimizing training- and test-data for accurate predictions, the impact of features, the impact of increasing the network, using and choosing embedding and much much more. Bottom line, if you’re interested in the field of recommendation systems, this one is a must.

This concludes my top 6 papers every modern data scientist must read — let me know if you think I missed a paper!
