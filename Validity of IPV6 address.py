valid_characters = set('ABCDEFabcdef:0123456789')

def ipv6_addr_is_valid(address):
    for current in address:
        if current not in valid_characters:
            return False


    address_list = address.split(":")

    for current in address_list:
        if len(current) > 4:
            return False  # Invalid segment

    return len(address_list) == 8

if __name__ == "__main__":
    address = input('Please enter an IP address: ')
    if ipv6_addr_is_valid(address):
        print("It is a valid IPv6 address.")
    else:
        print("It is not a valid IPv6 address.")