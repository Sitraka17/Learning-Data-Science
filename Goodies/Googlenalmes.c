{
 "cells": [
  {
   "cell_type": "markdown",
   "metadata": {
    "dc": {
     "key": "4"
    },
    "deletable": false,
    "editable": false,
    "run_control": {
     "frozen": true
    },
    "tags": [
     "context"
    ]
   },
   "source": [
    "## 1. The brief\n",
    "<p>Imagine working for a digital marketing agency, and the agency is approached by a massive online retailer of furniture. They want to test our skills at creating large campaigns for all of their website. We are tasked with creating a prototype set of keywords for search campaigns for their sofas section. The client says that they want us to generate keywords for the following products: </p>\n",
    "<ul>\n",
    "<li>sofas</li>\n",
    "<li>convertible sofas</li>\n",
    "<li>love seats</li>\n",
    "<li>recliners</li>\n",
    "<li>sofa beds</li>\n",
    "</ul>\n",
    "<p><strong>The brief</strong>: The client is generally a low-cost retailer, offering many promotions and discounts. We will need to focus on such keywords. We will also need to move away from luxury keywords and topics, as we are targeting price-sensitive customers. Because we are going to be tight on budget, it would be good to focus on a tightly targeted set of keywords and make sure they are all set to exact and phrase match.</p>\n",
    "<p>Based on the brief above we will first need to generate a list of words, that together with the products given above would make for good keywords. Here are some examples:</p>\n",
    "<ul>\n",
    "<li>Products: sofas, recliners</li>\n",
    "<li>Words: buy, prices</li>\n",
    "</ul>\n",
    "<p>The resulting keywords: 'buy sofas', 'sofas buy', 'buy recliners', 'recliners buy',\n",
    "          'prices sofas', 'sofas prices', 'prices recliners', 'recliners prices'.</p>\n",
    "<p>As a final result, we want to have a DataFrame that looks like this: </p>\n",
    "<table>\n",
    "<thead>\n",
    "<tr>\n",
    "<th>Campaign</th>\n",
    "<th>Ad Group</th>\n",
    "<th>Keyword</th>\n",
    "<th>Criterion Type</th>\n",
    "</tr>\n",
    "</thead>\n",
    "<tbody>\n",
    "<tr>\n",
    "<td>Campaign1</td>\n",
    "<td>AdGroup_1</td>\n",
    "<td>keyword 1a</td>\n",
    "<td>Exact</td>\n",
    "</tr>\n",
    "<tr>\n",
    "<td>Campaign1</td>\n",
    "<td>AdGroup_1</td>\n",
    "<td>keyword 1a</td>\n",
    "<td>Phrase</td>\n",
    "</tr>\n",
    "<tr>\n",
    "<td>Campaign1</td>\n",
    "<td>AdGroup_1</td>\n",
    "<td>keyword 1b</td>\n",
    "<td>Exact</td>\n",
    "</tr>\n",
    "<tr>\n",
    "<td>Campaign1</td>\n",
    "<td>AdGroup_1</td>\n",
    "<td>keyword 1b</td>\n",
    "<td>Phrase</td>\n",
    "</tr>\n",
    "<tr>\n",
    "<td>Campaign1</td>\n",
    "<td>AdGroup_2</td>\n",
    "<td>keyword 2a</td>\n",
    "<td>Exact</td>\n",
    "</tr>\n",
    "<tr>\n",
    "<td>Campaign1</td>\n",
    "<td>AdGroup_2</td>\n",
    "<td>keyword 2a</td>\n",
    "<td>Phrase</td>\n",
    "</tr>\n",
    "</tbody>\n",
    "</table>\n",
    "<p>The first step is to come up with a list of words that users might use to express their desire in buying low-cost sofas.</p>"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 1,
   "metadata": {
    "dc": {
     "key": "4"
    },
    "tags": [
     "sample_code"
    ]
   },
   "outputs": [
    {
     "data": {
      "text/plain": [
       "['buy',\n",
       " 'price',\n",
       " 'discount',\n",
       " 'promotion',\n",
       " 'promo',\n",
       " 'shop',\n",
       " 'buying',\n",
       " 'prices',\n",
       " 'pricing',\n",
       " 'shopping',\n",
       " 'discounts',\n",
       " 'promos',\n",
       " 'ecommerce',\n",
       " 'e commerce',\n",
       " 'buy online',\n",
       " 'shop online',\n",
       " 'cheap',\n",
       " 'best price',\n",
       " 'lowest price',\n",
       " 'cheapest',\n",
       " 'best value',\n",
       " 'offer',\n",
       " 'offers',\n",
       " 'promotions',\n",
       " 'purchase',\n",
       " 'sale',\n",
       " 'bargain',\n",
       " 'affordable',\n",
       " 'cheap',\n",
       " 'low',\n",
       " 'budget',\n",
       " 'inexpensive',\n",
       " 'economical',\n",
       " 'amazon',\n",
       " 'e-commerce']"
      ]
     },
     "execution_count": 1,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "# List of words to pair with products\n",
    "words = ['buy', 'price', 'discount', 'promotion', 'promo', 'shop', \n",
    "         'buying', 'prices', 'pricing', 'shopping', 'discounts', \n",
    "         'promos', 'ecommerce', 'e commerce', 'buy online',\n",
    "         'shop online', 'cheap', 'best price', 'lowest price',\n",
    "         'cheapest', 'best value', 'offer', 'offers', 'promotions',\n",
    "         'purchase', 'sale', 'bargain', 'affordable',\n",
    "         'cheap', 'low', 'budget', 'inexpensive', 'economical','amazon','e-commerce']\n",
    "# Print list of words\n",
    "# ... YOUR CODE FOR TASK 1 ...\n",
    "words"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {
    "dc": {
     "key": "11"
    },
    "deletable": false,
    "editable": false,
    "run_control": {
     "frozen": true
    },
    "tags": [
     "context"
    ]
   },
   "source": [
    "## 2. Combine the words with the product names\n",
    "<p>Imagining all the possible combinations of keywords can be stressful! But not for us, because we are keyword ninjas! We know how to translate campaign briefs into Python data structures and can imagine the resulting DataFrames that we need to create.</p>\n",
    "<p>Now that we have brainstormed the words that work well with the brief that we received, it is now time to combine them with the product names to generate meaningful search keywords. We want to combine every word with every product once before, and once after, as seen in the example above.</p>\n",
    "<p>As a quick reminder, for the product 'recliners' and the words 'buy' and 'price' for example, we would want to generate the following combinations: </p>\n",
    "<p>buy recliners<br>\n",
    "recliners buy<br>\n",
    "price recliners<br>\n",
    "recliners price<br>\n",
    "...  </p>\n",
    "<p>and so on for all the words and products that we have.</p>"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 2,
   "metadata": {
    "dc": {
     "key": "11"
    },
    "tags": [
     "sample_code"
    ]
   },
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "[['sofas', 'sofas buy'], ['sofas', 'buy sofas'], ['sofas', 'sofas price'], ['sofas', 'price sofas'], ['sofas', 'sofas discount'], ['sofas', 'discount sofas'], ['sofas', 'sofas promotion'], ['sofas', 'promotion sofas'], ['sofas', 'sofas promo'], ['sofas', 'promo sofas'], ['sofas', 'sofas shop'], ['sofas', 'shop sofas'], ['sofas', 'sofas buying'], ['sofas', 'buying sofas'], ['sofas', 'sofas prices'], ['sofas', 'prices sofas'], ['sofas', 'sofas pricing'], ['sofas', 'pricing sofas'], ['sofas', 'sofas shopping'], ['sofas', 'shopping sofas'], ['sofas', 'sofas discounts'], ['sofas', 'discounts sofas'], ['sofas', 'sofas promos'], ['sofas', 'promos sofas'], ['sofas', 'sofas ecommerce'], ['sofas', 'ecommerce sofas'], ['sofas', 'sofas e commerce'], ['sofas', 'e commerce sofas'], ['sofas', 'sofas buy online'], ['sofas', 'buy online sofas'], ['sofas', 'sofas shop online'], ['sofas', 'shop online sofas'], ['sofas', 'sofas cheap'], ['sofas', 'cheap sofas'], ['sofas', 'sofas best price'], ['sofas', 'best price sofas'], ['sofas', 'sofas lowest price'], ['sofas', 'lowest price sofas'], ['sofas', 'sofas cheapest'], ['sofas', 'cheapest sofas'], ['sofas', 'sofas best value'], ['sofas', 'best value sofas'], ['sofas', 'sofas offer'], ['sofas', 'offer sofas'], ['sofas', 'sofas offers'], ['sofas', 'offers sofas'], ['sofas', 'sofas promotions'], ['sofas', 'promotions sofas'], ['sofas', 'sofas purchase'], ['sofas', 'purchase sofas'], ['sofas', 'sofas sale'], ['sofas', 'sale sofas'], ['sofas', 'sofas bargain'], ['sofas', 'bargain sofas'], ['sofas', 'sofas affordable'], ['sofas', 'affordable sofas'], ['sofas', 'sofas cheap'], ['sofas', 'cheap sofas'], ['sofas', 'sofas low'], ['sofas', 'low sofas'], ['sofas', 'sofas budget'], ['sofas', 'budget sofas'], ['sofas', 'sofas inexpensive'], ['sofas', 'inexpensive sofas'], ['sofas', 'sofas economical'], ['sofas', 'economical sofas'], ['sofas', 'sofas amazon'], ['sofas', 'amazon sofas'], ['sofas', 'sofas e-commerce'], ['sofas', 'e-commerce sofas'], ['convertible sofas', 'convertible sofas buy'], ['convertible sofas', 'buy convertible sofas'], ['convertible sofas', 'convertible sofas price'], ['convertible sofas', 'price convertible sofas'], ['convertible sofas', 'convertible sofas discount'], ['convertible sofas', 'discount convertible sofas'], ['convertible sofas', 'convertible sofas promotion'], ['convertible sofas', 'promotion convertible sofas'], ['convertible sofas', 'convertible sofas promo'], ['convertible sofas', 'promo convertible sofas'], ['convertible sofas', 'convertible sofas shop'], ['convertible sofas', 'shop convertible sofas'], ['convertible sofas', 'convertible sofas buying'], ['convertible sofas', 'buying convertible sofas'], ['convertible sofas', 'convertible sofas prices'], ['convertible sofas', 'prices convertible sofas'], ['convertible sofas', 'convertible sofas pricing'], ['convertible sofas', 'pricing convertible sofas'], ['convertible sofas', 'convertible sofas shopping'], ['convertible sofas', 'shopping convertible sofas'], ['convertible sofas', 'convertible sofas discounts'], ['convertible sofas', 'discounts convertible sofas'], ['convertible sofas', 'convertible sofas promos'], ['convertible sofas', 'promos convertible sofas'], ['convertible sofas', 'convertible sofas ecommerce'], ['convertible sofas', 'ecommerce convertible sofas'], ['convertible sofas', 'convertible sofas e commerce'], ['convertible sofas', 'e commerce convertible sofas'], ['convertible sofas', 'convertible sofas buy online'], ['convertible sofas', 'buy online convertible sofas'], ['convertible sofas', 'convertible sofas shop online'], ['convertible sofas', 'shop online convertible sofas'], ['convertible sofas', 'convertible sofas cheap'], ['convertible sofas', 'cheap convertible sofas'], ['convertible sofas', 'convertible sofas best price'], ['convertible sofas', 'best price convertible sofas'], ['convertible sofas', 'convertible sofas lowest price'], ['convertible sofas', 'lowest price convertible sofas'], ['convertible sofas', 'convertible sofas cheapest'], ['convertible sofas', 'cheapest convertible sofas'], ['convertible sofas', 'convertible sofas best value'], ['convertible sofas', 'best value convertible sofas'], ['convertible sofas', 'convertible sofas offer'], ['convertible sofas', 'offer convertible sofas'], ['convertible sofas', 'convertible sofas offers'], ['convertible sofas', 'offers convertible sofas'], ['convertible sofas', 'convertible sofas promotions'], ['convertible sofas', 'promotions convertible sofas'], ['convertible sofas', 'convertible sofas purchase'], ['convertible sofas', 'purchase convertible sofas'], ['convertible sofas', 'convertible sofas sale'], ['convertible sofas', 'sale convertible sofas'], ['convertible sofas', 'convertible sofas bargain'], ['convertible sofas', 'bargain convertible sofas'], ['convertible sofas', 'convertible sofas affordable'], ['convertible sofas', 'affordable convertible sofas'], ['convertible sofas', 'convertible sofas cheap'], ['convertible sofas', 'cheap convertible sofas'], ['convertible sofas', 'convertible sofas low'], ['convertible sofas', 'low convertible sofas'], ['convertible sofas', 'convertible sofas budget'], ['convertible sofas', 'budget convertible sofas'], ['convertible sofas', 'convertible sofas inexpensive'], ['convertible sofas', 'inexpensive convertible sofas'], ['convertible sofas', 'convertible sofas economical'], ['convertible sofas', 'economical convertible sofas'], ['convertible sofas', 'convertible sofas amazon'], ['convertible sofas', 'amazon convertible sofas'], ['convertible sofas', 'convertible sofas e-commerce'], ['convertible sofas', 'e-commerce convertible sofas'], ['love seats', 'love seats buy'], ['love seats', 'buy love seats'], ['love seats', 'love seats price'], ['love seats', 'price love seats'], ['love seats', 'love seats discount'], ['love seats', 'discount love seats'], ['love seats', 'love seats promotion'], ['love seats', 'promotion love seats'], ['love seats', 'love seats promo'], ['love seats', 'promo love seats'], ['love seats', 'love seats shop'], ['love seats', 'shop love seats'], ['love seats', 'love seats buying'], ['love seats', 'buying love seats'], ['love seats', 'love seats prices'], ['love seats', 'prices love seats'], ['love seats', 'love seats pricing'], ['love seats', 'pricing love seats'], ['love seats', 'love seats shopping'], ['love seats', 'shopping love seats'], ['love seats', 'love seats discounts'], ['love seats', 'discounts love seats'], ['love seats', 'love seats promos'], ['love seats', 'promos love seats'], ['love seats', 'love seats ecommerce'], ['love seats', 'ecommerce love seats'], ['love seats', 'love seats e commerce'], ['love seats', 'e commerce love seats'], ['love seats', 'love seats buy online'], ['love seats', 'buy online love seats'], ['love seats', 'love seats shop online'], ['love seats', 'shop online love seats'], ['love seats', 'love seats cheap'], ['love seats', 'cheap love seats'], ['love seats', 'love seats best price'], ['love seats', 'best price love seats'], ['love seats', 'love seats lowest price'], ['love seats', 'lowest price love seats'], ['love seats', 'love seats cheapest'], ['love seats', 'cheapest love seats'], ['love seats', 'love seats best value'], ['love seats', 'best value love seats'], ['love seats', 'love seats offer'], ['love seats', 'offer love seats'], ['love seats', 'love seats offers'], ['love seats', 'offers love seats'], ['love seats', 'love seats promotions'], ['love seats', 'promotions love seats'], ['love seats', 'love seats purchase'], ['love seats', 'purchase love seats'], ['love seats', 'love seats sale'], ['love seats', 'sale love seats'], ['love seats', 'love seats bargain'], ['love seats', 'bargain love seats'], ['love seats', 'love seats affordable'], ['love seats', 'affordable love seats'], ['love seats', 'love seats cheap'], ['love seats', 'cheap love seats'], ['love seats', 'love seats low'], ['love seats', 'low love seats'], ['love seats', 'love seats budget'], ['love seats', 'budget love seats'], ['love seats', 'love seats inexpensive'], ['love seats', 'inexpensive love seats'], ['love seats', 'love seats economical'], ['love seats', 'economical love seats'], ['love seats', 'love seats amazon'], ['love seats', 'amazon love seats'], ['love seats', 'love seats e-commerce'], ['love seats', 'e-commerce love seats'], ['recliners', 'recliners buy'], ['recliners', 'buy recliners'], ['recliners', 'recliners price'], ['recliners', 'price recliners'], ['recliners', 'recliners discount'], ['recliners', 'discount recliners'], ['recliners', 'recliners promotion'], ['recliners', 'promotion recliners'], ['recliners', 'recliners promo'], ['recliners', 'promo recliners'], ['recliners', 'recliners shop'], ['recliners', 'shop recliners'], ['recliners', 'recliners buying'], ['recliners', 'buying recliners'], ['recliners', 'recliners prices'], ['recliners', 'prices recliners'], ['recliners', 'recliners pricing'], ['recliners', 'pricing recliners'], ['recliners', 'recliners shopping'], ['recliners', 'shopping recliners'], ['recliners', 'recliners discounts'], ['recliners', 'discounts recliners'], ['recliners', 'recliners promos'], ['recliners', 'promos recliners'], ['recliners', 'recliners ecommerce'], ['recliners', 'ecommerce recliners'], ['recliners', 'recliners e commerce'], ['recliners', 'e commerce recliners'], ['recliners', 'recliners buy online'], ['recliners', 'buy online recliners'], ['recliners', 'recliners shop online'], ['recliners', 'shop online recliners'], ['recliners', 'recliners cheap'], ['recliners', 'cheap recliners'], ['recliners', 'recliners best price'], ['recliners', 'best price recliners'], ['recliners', 'recliners lowest price'], ['recliners', 'lowest price recliners'], ['recliners', 'recliners cheapest'], ['recliners', 'cheapest recliners'], ['recliners', 'recliners best value'], ['recliners', 'best value recliners'], ['recliners', 'recliners offer'], ['recliners', 'offer recliners'], ['recliners', 'recliners offers'], ['recliners', 'offers recliners'], ['recliners', 'recliners promotions'], ['recliners', 'promotions recliners'], ['recliners', 'recliners purchase'], ['recliners', 'purchase recliners'], ['recliners', 'recliners sale'], ['recliners', 'sale recliners'], ['recliners', 'recliners bargain'], ['recliners', 'bargain recliners'], ['recliners', 'recliners affordable'], ['recliners', 'affordable recliners'], ['recliners', 'recliners cheap'], ['recliners', 'cheap recliners'], ['recliners', 'recliners low'], ['recliners', 'low recliners'], ['recliners', 'recliners budget'], ['recliners', 'budget recliners'], ['recliners', 'recliners inexpensive'], ['recliners', 'inexpensive recliners'], ['recliners', 'recliners economical'], ['recliners', 'economical recliners'], ['recliners', 'recliners amazon'], ['recliners', 'amazon recliners'], ['recliners', 'recliners e-commerce'], ['recliners', 'e-commerce recliners'], ['sofa beds', 'sofa beds buy'], ['sofa beds', 'buy sofa beds'], ['sofa beds', 'sofa beds price'], ['sofa beds', 'price sofa beds'], ['sofa beds', 'sofa beds discount'], ['sofa beds', 'discount sofa beds'], ['sofa beds', 'sofa beds promotion'], ['sofa beds', 'promotion sofa beds'], ['sofa beds', 'sofa beds promo'], ['sofa beds', 'promo sofa beds'], ['sofa beds', 'sofa beds shop'], ['sofa beds', 'shop sofa beds'], ['sofa beds', 'sofa beds buying'], ['sofa beds', 'buying sofa beds'], ['sofa beds', 'sofa beds prices'], ['sofa beds', 'prices sofa beds'], ['sofa beds', 'sofa beds pricing'], ['sofa beds', 'pricing sofa beds'], ['sofa beds', 'sofa beds shopping'], ['sofa beds', 'shopping sofa beds'], ['sofa beds', 'sofa beds discounts'], ['sofa beds', 'discounts sofa beds'], ['sofa beds', 'sofa beds promos'], ['sofa beds', 'promos sofa beds'], ['sofa beds', 'sofa beds ecommerce'], ['sofa beds', 'ecommerce sofa beds'], ['sofa beds', 'sofa beds e commerce'], ['sofa beds', 'e commerce sofa beds'], ['sofa beds', 'sofa beds buy online'], ['sofa beds', 'buy online sofa beds'], ['sofa beds', 'sofa beds shop online'], ['sofa beds', 'shop online sofa beds'], ['sofa beds', 'sofa beds cheap'], ['sofa beds', 'cheap sofa beds'], ['sofa beds', 'sofa beds best price'], ['sofa beds', 'best price sofa beds'], ['sofa beds', 'sofa beds lowest price'], ['sofa beds', 'lowest price sofa beds'], ['sofa beds', 'sofa beds cheapest'], ['sofa beds', 'cheapest sofa beds'], ['sofa beds', 'sofa beds best value'], ['sofa beds', 'best value sofa beds'], ['sofa beds', 'sofa beds offer'], ['sofa beds', 'offer sofa beds'], ['sofa beds', 'sofa beds offers'], ['sofa beds', 'offers sofa beds'], ['sofa beds', 'sofa beds promotions'], ['sofa beds', 'promotions sofa beds'], ['sofa beds', 'sofa beds purchase'], ['sofa beds', 'purchase sofa beds'], ['sofa beds', 'sofa beds sale'], ['sofa beds', 'sale sofa beds'], ['sofa beds', 'sofa beds bargain'], ['sofa beds', 'bargain sofa beds'], ['sofa beds', 'sofa beds affordable'], ['sofa beds', 'affordable sofa beds'], ['sofa beds', 'sofa beds cheap'], ['sofa beds', 'cheap sofa beds'], ['sofa beds', 'sofa beds low'], ['sofa beds', 'low sofa beds'], ['sofa beds', 'sofa beds budget'], ['sofa beds', 'budget sofa beds'], ['sofa beds', 'sofa beds inexpensive'], ['sofa beds', 'inexpensive sofa beds'], ['sofa beds', 'sofa beds economical'], ['sofa beds', 'economical sofa beds'], ['sofa beds', 'sofa beds amazon'], ['sofa beds', 'amazon sofa beds'], ['sofa beds', 'sofa beds e-commerce'], ['sofa beds', 'e-commerce sofa beds']]\n"
     ]
    }
   ],
   "source": [
    "products = ['sofas', 'convertible sofas', 'love seats', 'recliners', 'sofa beds']\n",
    "\n",
    "# Create an empty list\n",
    "keywords_list = []\n",
    "\n",
    "# Loop through products\n",
    "for product in products:\n",
    "    # Loop through words\n",
    "    for word in words:\n",
    "        # Append combinations\n",
    "        keywords_list.append([product, product + ' ' + word])\n",
    "        keywords_list.append([product, word + ' ' + product])\n",
    "        \n",
    "# Inspect keyword list\n",
    "from pprint import pprint\n",
    "print(keywords_list)"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {
    "dc": {
     "key": "18"
    },
    "deletable": false,
    "editable": false,
    "run_control": {
     "frozen": true
    },
    "tags": [
     "context"
    ]
   },
   "source": [
    "## 3. Convert the list of lists into a DataFrame\n",
    "<p>Now we want to convert this list of lists into a DataFrame so we can easily manipulate it and manage the final output.</p>"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 3,
   "metadata": {
    "dc": {
     "key": "18"
    },
    "tags": [
     "sample_code"
    ]
   },
   "outputs": [
    {
     "data": {
      "text/html": [
       "<div>\n",
       "<style scoped>\n",
       "    .dataframe tbody tr th:only-of-type {\n",
       "        vertical-align: middle;\n",
       "    }\n",
       "\n",
       "    .dataframe tbody tr th {\n",
       "        vertical-align: top;\n",
       "    }\n",
       "\n",
       "    .dataframe thead th {\n",
       "        text-align: right;\n",
       "    }\n",
       "</style>\n",
       "<table border=\"1\" class=\"dataframe\">\n",
       "  <thead>\n",
       "    <tr style=\"text-align: right;\">\n",
       "      <th></th>\n",
       "      <th>0</th>\n",
       "      <th>1</th>\n",
       "    </tr>\n",
       "  </thead>\n",
       "  <tbody>\n",
       "    <tr>\n",
       "      <th>0</th>\n",
       "      <td>sofas</td>\n",
       "      <td>sofas buy</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>1</th>\n",
       "      <td>sofas</td>\n",
       "      <td>buy sofas</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>2</th>\n",
       "      <td>sofas</td>\n",
       "      <td>sofas price</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>3</th>\n",
       "      <td>sofas</td>\n",
       "      <td>price sofas</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>4</th>\n",
       "      <td>sofas</td>\n",
       "      <td>sofas discount</td>\n",
       "    </tr>\n",
       "  </tbody>\n",
       "</table>\n",
       "</div>"
      ],
      "text/plain": [
       "       0               1\n",
       "0  sofas       sofas buy\n",
       "1  sofas       buy sofas\n",
       "2  sofas     sofas price\n",
       "3  sofas     price sofas\n",
       "4  sofas  sofas discount"
      ]
     },
     "execution_count": 3,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "# Load library\n",
    "# ... YOUR CODE FOR TASK 3 ...\n",
    "import pandas as pd\n",
    "\n",
    "# Create a DataFrame from list\n",
    "keywords_df = pd.DataFrame.from_records(keywords_list)\n",
    "\n",
    "# Print the keywords DataFrame to explore it\n",
    "# ... YOUR CODE FOR TASK 3 ...\n",
    "keywords_df.head()"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {
    "dc": {
     "key": "25"
    },
    "deletable": false,
    "editable": false,
    "run_control": {
     "frozen": true
    },
    "tags": [
     "context"
    ]
   },
   "source": [
    "## 4. Rename the columns of the DataFrame\n",
    "<p>Before we can upload this table of keywords, we will need to give the columns meaningful names. If we inspect the DataFrame we just created above, we can see that the columns are currently named <code>0</code> and <code>1</code>. <code>Ad Group</code> (example: \"sofas\") and <code>Keyword</code> (example: \"sofas buy\") are much more appropriate names.</p>"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 4,
   "metadata": {
    "dc": {
     "key": "25"
    },
    "tags": [
     "sample_code"
    ]
   },
   "outputs": [
    {
     "data": {
      "text/html": [
       "<div>\n",
       "<style scoped>\n",
       "    .dataframe tbody tr th:only-of-type {\n",
       "        vertical-align: middle;\n",
       "    }\n",
       "\n",
       "    .dataframe tbody tr th {\n",
       "        vertical-align: top;\n",
       "    }\n",
       "\n",
       "    .dataframe thead th {\n",
       "        text-align: right;\n",
       "    }\n",
       "</style>\n",
       "<table border=\"1\" class=\"dataframe\">\n",
       "  <thead>\n",
       "    <tr style=\"text-align: right;\">\n",
       "      <th></th>\n",
       "      <th>Ad Group</th>\n",
       "      <th>Keyword</th>\n",
       "    </tr>\n",
       "  </thead>\n",
       "  <tbody>\n",
       "    <tr>\n",
       "      <th>0</th>\n",
       "      <td>sofas</td>\n",
       "      <td>sofas buy</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>1</th>\n",
       "      <td>sofas</td>\n",
       "      <td>buy sofas</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>2</th>\n",
       "      <td>sofas</td>\n",
       "      <td>sofas price</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>3</th>\n",
       "      <td>sofas</td>\n",
       "      <td>price sofas</td>\n",
       "    </tr>\n",
       "    <tr>\n",
       "      <th>4</th>\n",
       "      <td>sofas</td>\n",
       "      <td>sofas discount</td>\n",
       "    </tr>\n",
       "  </tbody>\n",
       "</table>\n",
       "</div>"
      ],
      "text/plain": [
       "  Ad Group         Keyword\n",
       "0    sofas       sofas buy\n",
       "1    sofas       buy sofas\n",
       "2    sofas     sofas price\n",
       "3    sofas     price sofas\n",
       "4    sofas  sofas discount"
      ]
     },
     "execution_count": 4,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "# Rename the columns of the DataFrame\n",
    "keywords_df = keywords_df.rename(columns={0: \"Ad Group\",1: \"Keyword\"})\n",
    "keywords_df.head()"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {
    "dc": {
     "key": "32"
    },
    "deletable": false,
    "editable": false,
    "run_control": {
     "frozen": true
    },
    "tags": [
     "context"
    ]
   },
   "source": [
    "## 5. Add a campaign column\n",
    "<p>Now we need to add some additional information to our DataFrame. \n",
    "We need a new column called <code>Campaign</code> for the campaign name. We want campaign names to be descriptive of our group of keywords and products, so let's call this campaign 'SEM_Sofas'.</p>"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 5,
   "metadata": {
    "dc": {
     "key": "32"
    },
    "tags": [
     "sample_code"
    ]
   },
   "outputs": [],
   "source": [
    "# Add a campaign column\n",
    "# ... YOUR CODE FOR TASK 5 ...\n",
    "keywords_df['Campaign']='SEM_Sofas'"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {
    "dc": {
     "key": "39"
    },
    "deletable": false,
    "editable": false,
    "run_control": {
     "frozen": true
    },
    "tags": [
     "context"
    ]
   },
   "source": [
    "## 6. Create the match type column\n",
    "<p>There are different keyword match types. One is exact match, which is for matching the exact term or are close variations of that exact term. Another match type is broad match, which means ads may show on searches that include misspellings, synonyms, related searches, and other relevant variations.</p>\n",
    "<p>Straight from Google's AdWords <a href=\"https://support.google.com/google-ads/answer/2497836?hl=en\">documentation</a>:</p>\n",
    "<blockquote>\n",
    "  <p>In general, the broader the match type, the more traffic potential that keyword will have, since your ads may be triggered more often. Conversely, a narrower match type means that your ads may show less often—but when they do, they’re likely to be more related to someone’s search.</p>\n",
    "</blockquote>\n",
    "<p>Since the client is tight on budget, we want to make sure all the keywords are in exact match at the beginning.</p>"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 6,
   "metadata": {
    "dc": {
     "key": "39"
    },
    "tags": [
     "sample_code"
    ]
   },
   "outputs": [],
   "source": [
    "# Add a criterion type column\n",
    "# ... YOUR CODE FOR TASK 6 ...\n",
    "keywords_df['Criterion Type']='Exact'"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {
    "dc": {
     "key": "46"
    },
    "deletable": false,
    "editable": false,
    "run_control": {
     "frozen": true
    },
    "tags": [
     "context"
    ]
   },
   "source": [
    "## 7. Duplicate all the keywords into 'phrase' match\n",
    "<p>The great thing about exact match is that it is very specific, and we can control the process very well. The tradeoff, however, is that:  </p>\n",
    "<ol>\n",
    "<li>The search volume for exact match is lower than other match types</li>\n",
    "<li>We can't possibly think of all the ways in which people search, and so, we are probably missing out on some high-quality keywords.</li>\n",
    "</ol>\n",
    "<p>So it's good to use another match called <em>phrase match</em> as a discovery mechanism to allow our ads to be triggered by keywords that include our exact match keywords, together with anything before (or after) them.</p>\n",
    "<p>Later on, when we launch the campaign, we can explore with modified broad match, broad match, and negative match types, for better visibility and control of our campaigns.</p>"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 7,
   "metadata": {
    "dc": {
     "key": "46"
    },
    "tags": [
     "sample_code"
    ]
   },
   "outputs": [],
   "source": [
    "# Make a copy of the keywords DataFrame\n",
    "keywords_phrase = keywords_df.copy()\n",
    "\n",
    "# Change criterion type match to phrase\n",
    "# ... YOUR CODE FOR TASK 7 ...\n",
    "keywords_phrase['Criterion Type']='Phrase'\n",
    "\n",
    "# Append the DataFrames\n",
    "keywords_df_final = keywords_df.append(keywords_phrase)"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {
    "dc": {
     "key": "53"
    },
    "deletable": false,
    "editable": false,
    "run_control": {
     "frozen": true
    },
    "tags": [
     "context"
    ]
   },
   "source": [
    "## 8. Save and summarize!\n",
    "<p>To upload our campaign, we need to save it as a CSV file. Then we will be able to import it to AdWords editor or BingAds editor. There is also the option of pasting the data into the editor if we want, but having easy access to the saved data is great so let's save to a CSV file!</p>\n",
    "<p>Looking at a summary of our campaign structure is good now that we've wrapped up our keyword work. We can do that by grouping by ad group and criterion type and counting by keyword. This summary shows us that we assigned specific keywords to specific ad groups, which are each part of a campaign. In essence, we are telling Google (or Bing, etc.) that we want any of the words in each ad group to trigger one of the ads in the same ad group. Separately, we will have to create another table for ads, which is a task for another day and would look something like this:</p>\n",
    "<table>\n",
    "<thead>\n",
    "<tr>\n",
    "<th>Campaign</th>\n",
    "<th>Ad Group</th>\n",
    "<th>Headline 1</th>\n",
    "<th>Headline 2</th>\n",
    "<th>Description</th>\n",
    "<th>Final URL</th>\n",
    "</tr>\n",
    "</thead>\n",
    "<tbody>\n",
    "<tr>\n",
    "<td>SEM_Sofas</td>\n",
    "<td>Sofas</td>\n",
    "<td>Looking for Quality Sofas?</td>\n",
    "<td>Explore Our Massive Collection</td>\n",
    "<td>30-day Returns With Free Delivery Within the US. Start Shopping Now</td>\n",
    "<td>DataCampSofas.com/sofas</td>\n",
    "</tr>\n",
    "<tr>\n",
    "<td>SEM_Sofas</td>\n",
    "<td>Sofas</td>\n",
    "<td>Looking for Affordable Sofas?</td>\n",
    "<td>Check Out Our Weekly Offers</td>\n",
    "<td>30-day Returns With Free Delivery Within the US. Start Shopping Now</td>\n",
    "<td>DataCampSofas.com/sofas</td>\n",
    "</tr>\n",
    "<tr>\n",
    "<td>SEM_Sofas</td>\n",
    "<td>Recliners</td>\n",
    "<td>Looking for Quality Recliners?</td>\n",
    "<td>Explore Our Massive Collection</td>\n",
    "<td>30-day Returns With Free Delivery Within the US. Start Shopping Now</td>\n",
    "<td>DataCampSofas.com/recliners</td>\n",
    "</tr>\n",
    "<tr>\n",
    "<td>SEM_Sofas</td>\n",
    "<td>Recliners</td>\n",
    "<td>Need Affordable Recliners?</td>\n",
    "<td>Check Out Our Weekly Offers</td>\n",
    "<td>30-day Returns With Free Delivery Within the US. Start Shopping Now</td>\n",
    "<td>DataCampSofas.com/recliners</td>\n",
    "</tr>\n",
    "</tbody>\n",
    "</table>\n",
    "<p>Together, these tables get us the sample <strong>keywords -> ads -> landing pages</strong> mapping shown in the diagram below.</p>\n",
    "<p><img src=\"https://s3.amazonaws.com/assets.datacamp.com/production/project_400/img/kwds_ads_lpages.png\" alt=\"Keywords-Ads-Landing pages flow\"></p>"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 8,
   "metadata": {
    "dc": {
     "key": "53"
    },
    "tags": [
     "sample_code"
    ]
   },
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "Ad Group           Criterion Type\n",
      "convertible sofas  Exact             70\n",
      "                   Phrase            70\n",
      "love seats         Exact             70\n",
      "                   Phrase            70\n",
      "recliners          Exact             70\n",
      "                   Phrase            70\n",
      "sofa beds          Exact             70\n",
      "                   Phrase            70\n",
      "sofas              Exact             70\n",
      "                   Phrase            70\n",
      "Name: Keyword, dtype: int64\n"
     ]
    }
   ],
   "source": [
    "# Save the final keywords to a CSV file\n",
    "# ... YOUR CODE FOR TASK 8 ...\n",
    "keywords_df.to_csv('keyords.csv', index=False)\n",
    "# View a summary of our campaign work\n",
    "summary = keywords_df_final.groupby(['Ad Group', 'Criterion Type'])['Keyword'].count()\n",
    "print(summary)"
   ]
  }
 ],
 "metadata": {
  "kernelspec": {
   "display_name": "Python 2",
   "language": "python",
   "name": "python2"
  },
  "language_info": {
   "codemirror_mode": {
    "name": "ipython",
    "version": 2
   },
   "file_extension": ".py",
   "mimetype": "text/x-python",
   "name": "python",
   "nbconvert_exporter": "python",
   "pygments_lexer": "ipython2",
   "version": "2.7.14"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 2
}
