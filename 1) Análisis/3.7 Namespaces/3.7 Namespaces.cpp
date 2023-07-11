#import <mso9.dll> no_namespace rename("DocumentProperties","DocumentPropertiesXL")
#import <vbe6ext.olb> no_namespace
#import <excel9.olb>

rename("DialogBox", "DialogBoxXL") \
rename("RGB", "RBGXL") \
rename("DocumentProperties", "DocumentPropertiesXL") \
no_dual_interfaces

#import <msword9.olb> rename("DialogBox", "DialogBoxWord") \
rename("RGB", "RBGWord") \
rename("DocumentProperties", "DocumentPropertiesWord") \
no_dual_interfaces
