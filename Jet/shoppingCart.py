def solution(requests):
    result = []
    cart = {}
    received_order = []
    for request in requests:
        request_tokens = request.split(" : ")
        command = request_tokens[0]
        if command == "checkout":
            cart = {}
            received_order = []
            continue
            
        argument = request_tokens[1]
        if command == "add":
            received_order.append(argument)
            cart.setdefault(argument,1)
        elif command == "remove":
            received_order.remove(argument)
            del cart[argument]
        elif command == "quantity_upd":
            item = request_tokens[1]
            qty = int(request_tokens[2])
            cart[item] += qty
    
    for item in received_order:
        result.append(f"{item} : {cart[item]}")
    return result

