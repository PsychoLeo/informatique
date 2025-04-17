import tweepy
import time

# Replace with your actual bearer token from Twitter Developer Portal
bearer_token = "AAAAAAAAAAAAAAAAAAAAANMe0QEAAAAAy8UsR7f8JTmP3q1JBbCGNocrmzA%3DPhCZ22ZjgEqNNj5MHJGDPRtcCT1L907YH0DMIkZ9zaLE9GDaSA"

# Create a Tweepy client for Twitter API v2
client = tweepy.Client(bearer_token=bearer_token)

# List of influential accounts (politics, economy, finance)
accounts = [
    "elonmusk",       # Economy/Finance (tech & business)
    "CNBC",           # Finance/Business News
    "WSJ",            # Business News
    "FinancialTimes", # Economy/Finance News
    "BBCBusiness",    # Economy/Finance News
]

# Retrieve and print the 5 latest tweets for each account
for account in accounts:
    try : 
        # Get the user details to extract the user ID
        user_response = client.get_user(username=account)
        if user_response.data is None:
            print(f"Utilisateur @{account} non trouvé.")
            continue

        user_id = user_response.data.id
        print(f"Tweets récents de @{account} :")

        # Retrieve the user's tweets (maximum 10 recent tweets)
        tweets_response = client.get_users_tweets(
            id=user_id,
            max_results=5,
            tweet_fields=["created_at", "text"]
        )
        
        if tweets_response.data:
            for tweet in tweets_response.data:
                print(f"- {tweet.created_at}: {tweet.text}\n")
        else:
            print("Aucun tweet trouvé pour cet utilisateur.\n")
    except tweepy.TooManyRequests :
        print("Rate limit atteint. Attente de 30 secondes...")
        time.sleep(30)  # attendre 30 secondes
        tweets_response = client.get_users_tweets(
            id=user_id,
            max_results=10,
            tweet_fields=["created_at", "text"]
        ) 
