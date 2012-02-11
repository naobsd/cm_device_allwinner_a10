# Release name
PRODUCT_RELEASE_NAME := A10

# Inherit some common CM stuff.
$(call inherit-product, vendor/cm/config/common_full_tablet_wifionly.mk)

# Inherit device configuration
$(call inherit-product, device/allwinner/a10/full_a10.mk)

## Device identifier. This must come after all inclusions
PRODUCT_DEVICE := a10
PRODUCT_NAME := cm_a10
PRODUCT_BRAND := Allwinner
PRODUCT_MODEL := A10
PRODUCT_MANUFACTURER := Allwinner

#Set build fingerprint / ID / Product Name ect.
PRODUCT_BUILD_PROP_OVERRIDES += PRODUCT_NAME=a10 BUILD_ID=IML77 BUILD_DISPLAY_ID=IML77 BUILD_FINGERPRINT="motorola/tervigon/wingray:4.0.3/IML77/239789:user/release-keys" PRIVATE_BUILD_DESC="tervigon-user 4.0.3 IML77 239789 release-keys"
