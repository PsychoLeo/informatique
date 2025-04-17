import os
import certifi

# Set the environment variable for SSL certificates
os.environ['SSL_CERT_FILE'] = certifi.where()
os.environ['REQUESTS_CA_BUNDLE'] = certifi.where()

import snscrape.modules.twitter as sntwitter
from datetime import datetime, timedelta, timezone

# Liste des noms d'utilisateur Twitter
usernames = [
    'Challenges', 'bfmbusiness', 'NCheron_bourse', 'charles_janus',
    'CryptoCobain', 'APompliano', 'VitalikButerin', 'rektcapital',
    'Novethic', 'elonmusk'
]

# Définir le délai de temps pour les tweets récents (par exemple, la dernière minute)
now = datetime.now(timezone.utc)
since_time = now - timedelta(minutes=60)

# Collecter les tweets récents
for username in usernames:
    print(f"Tweets récents de @{username} :")
    try:
        for tweet in sntwitter.TwitterUserScraper(username).get_items():
            tweet_date = tweet.date.replace(tzinfo=None)
            if tweet_date >= since_time:
                print(f"- {tweet_date}: {tweet.content}")
            else:
                break
    except Exception as e:
        print(f"Erreur lors de la récupération des tweets pour @{username}: {e}")
    print()
