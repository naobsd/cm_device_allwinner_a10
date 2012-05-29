# Release name
PRODUCT_RELEASE_NAME := A10GB

# Boot animation
TARGET_BOOTANIMATION_NAME := vertical-320x480

# Inherit some common CM stuff.
$(call inherit-product, vendor/cm/config/common_full_tablet_wifionly.mk)

# Inherit device configuration
$(call inherit-product, device/allwinner/a10gb/full_a10gb.mk)

## Device identifier. This must come after all inclusions
PRODUCT_DEVICE := a10gb
PRODUCT_NAME := cm_a10gb
PRODUCT_BRAND := Allwinner
PRODUCT_MODEL := A10GB
PRODUCT_MANUFACTURER := Allwinner

#Set build fingerprint / ID / Product Name ect.
PRODUCT_BUILD_PROP_OVERRIDES += PRODUCT_NAME=a10gb BUILD_FINGERPRINT="motorola/tervigon/wingray:4.0.4/IMM76/292727:user/release-keys" PRIVATE_BUILD_DESC="tervigon-user 4.0.4 IMM76 292727 release-keys"
