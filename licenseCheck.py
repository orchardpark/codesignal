from sqlalchemy import Column, String, Integer, ForeignKey, func
from sqlalchemy.orm import relationship, backref, sessionmaker
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import create_engine


Base = declarative_base()


class Product(Base):
    __tablename__ = 'products'
    product_name = Column(String, primary_key=True)
    product_licenses = Column(String)

class User(Base):
    __tablename__ = 'users'
    user_name = Column(String, primary_key=True)
    product_licenses = Column(String)

def main():
    engine = create_engine("mysql+mysqlconnector://test:@db/ri_db")
    session = sessionmaker()
    session.configure(bind=engine)
    s = session()

    # Write your code here
    product_names = []
    product_licenses = {}
    products = s.query(Product).all()
    for product in products:
        for license in product.product_licenses.split(","):
            product_licenses[license] = product.product_name
        product_names.append(product.product_name)
    users = s.query(User).all()
    for user in users:
        print("User {}:".format(user.user_name))
        user_products = set([product_licenses.get(l, "Naaa") for l in user.product_licenses.split(",")])
        for product_name in product_names:
            print("  {}: {}".format(product_name, 'true' if product_name in user_products else 'false'))
        
        

    s.commit()
    s.close()

if __name__ == '__main__':
    main()
